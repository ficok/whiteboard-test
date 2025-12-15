Trebalo bi da postoji stash manager. Sta ako response nikad ne stigne do scene? Item
koji je optimisticno nacrtan ce ostati nacrtan, a ne bi smeo.
Trebalo bi ubaciti i TTL stash-ovane operacije, a da manager
(mozda u drugom thread-u) prolazi kroz stashovane iteme i kad im prodje TTL,
brise ih.


Drawables
Postoji Drawable: Element, Draft, Item.
    Element je commit-ovan podatak. On ne sme da se menja
    Draft je strukturno isti kao Element, ali predstavlja drugo stanje ovog podatka:
        Draft direktno pravi tool prilikom crtanja. On moze da se menja i konvertuje
        u Element kad se salje zahtev za cuvanje na backend, ali se takodje od njega
        pravi privremeni Item za optimisticno crtanje
    Item je reprezentacija Elementa, iscrtana na sceni.


unique_ptr
Ova odluka je dosta bitna. Ako koristimo smart pointere, onda ne mozemo da ih cuvamo
u Qt kolekcijama; moramo u STL.
Omogucava nam da imamo polimorfne klase.
Otezava serijalizaciju i deserijalizaciju, moramo da imamo Factory klase za to.
Manje efikasno u nekim slucajevima: za undo/redo moraju da se kloniraju podaci,
move/copy je skuplji.
Dobijamo polimorfizam i prirodan OOP, bez ElementData varijanata i visitora.
Kod serijalizacije i deserijalizacije, moramo da imamo neki enum tipova elementa
i kad god hocemo da deserijalizujemo neke podatke, prvo citamo tip elementa
i onda pozivamo Factory method koji ce na osnovu tog tipa da napravi ispravan objekat.
Najveci problem predstavlja slanje preko signala. U slucaju undo/redo, kao i u collaboration
slucaju kad neki drugi klijent napravi element, u scenu element stize preko signala od
dokumenta. Medjutim, unique_ptr i signali ne rade zajedno (jer signal pokusava da napravi
kopiju onoga sto se salje, a unique_ptr nije copyable). Ne mogu da posaljem ni po
vrednosti, jer ce doci do slajsovanja (posto je potpis signala void elementAdded(DocumentElement)).


Ako koristimo data-driven pristup, koristimo Qt kolekcije, ali onda ne mozemo
da imamo polimorfne klase. Moramo da imamo samo jedan DrawableElement, a razlikovacemo
tipove elemenata medjusobno preko ElementData strukture. Ona sadrzi potrebne informacije
da se opise element (na primer, vektor tacaka).
Prednost je sto svuda koristimo Qt kontejnere i ne moramo da brinemo o konverziji,
serijalizacija/deserijalizacija su trivijalni. Sve prenosimo po vrednosti i mozemo
da koristimo move semantiku da nam to prenosenje bude efikasnije.
Qt kolekcije interno sve cuvaju na heap-u svakako, tako da cuvanje podataka npr.
u dokumentu ce svakako biti radjeno na heap-u (jer elemente cuvamo u Qt kontejnerima),
tako da necemo napraviti stack overflow.
Ono sto je problematicno je da ne mozemo da imamo polimorfizam, to jest, da
imamo kolekciju DrawableElements, dok svaki od njih predstavlja neki konkretan
element, poput StrokeElement, CircleElement itd. Zato moramo da imamo
ElementData koji opisuje razlicite elemente (StrokeData, CircleData)
Stoga, i DrawableItem funkcionise isto, moramo da imamo Visitor pattern koji na osnovu tipa ElementData
zna kako da ih crta.

Moja odluka:
DrawableElement ce da bude data-driven.
Postojace Factory koji ume da napravi odgovarajuc Item iz konkretnog tipa podataka
unutar DrawableElement-a.
DrawableElement sa podacima ce prenosi kroz ceo pipeline (Tool - Controller - Backend - Document),
cuva se u Command za undo/redo i prenosi se preko signala.
Draft se pravi samo u Tool-u i konvertuje se u DrawableElement i u odgovarajuc DrawableItem.
DrawableItem-i se cuvaju u sceni u stash-u za optimisticno crtanje i nigde drugo.

Scena iz DrawableElementa ume da napravi odgovarajuc DrawableItem pomocu factory metode.
Tool iz Draft-a ume da napravi DrawableElement. Tool ce biti polimorfan i svaki specifican
tool umece da napravi data za DrawableElement.
