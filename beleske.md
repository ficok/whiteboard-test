- MVC pipeline je asinhron. signali i slotovi se koriste da azuriraju view kad promene ne
  dolaze preko direktnog user input-a (nego undo, redo, paste...)
- Cuvanje elemenata u vektoru ce biti problematicno zbog brisanja. Cuvanje u mapi
  ce biti problematicno zbog orderinga. Treba smisliti resenje za to.


TODO:
- Response i Request klase
- preko cega se prenose zahtevi za prethodnom/narednom stranicom i kako? to mi nema
  smisla da ide kao Request/Response
- kad napravis Response i Request klase, prodji kroz ceo pipeline (DocumentService itd)
  i prilagodi te metode
