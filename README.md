# Planes-OOP-Project

# Sistem de Rezervare Bilete de Avion

Acesta este un proiect C++ care implementează un sistem de rezervare a biletelor de avion. Aplicația permite operatorilor să se logheze și utilizatorilor să se înregistreze, să se autentifice și să rezerve bilete pentru zboruri domestice și internaționale.

## Funcționalități

- Autentificare operator cu username și parolă criptată
- Înregistrare și autentificare utilizator 
- Rezervare bilete pentru zboruri domestice și internaționale
- Selectare dată, oraș de plecare și destinație, companie aeriană și oră de zbor
- Generare cod unic de rezervare (PNR)
- Stocare date utilizatori și rezervări în fișiere text

## Utilizare

1. Compilați codul sursă C++
2. Rulați executabilul generat
3. Alegeți opțiunea dorită din meniu (operator, utilizator existent, utilizator nou)
4. Urmați instrucțiunile de pe ecran pentru a vă loga, înregistra sau rezerva un bilet

## Structura Proiectului

- `main()`: Funcția principală care orchestrează fluxul programului
- `class RSA`: Implementează criptarea RSA pentru parolele utilizatorilor
- `class Try_to_login`: Gestionează autentificarea operatorilor și utilizatorilor
- `class d_booking`: Gestionează rezervările pentru zboruri domestice  
- `class i_booking`: Gestionează rezervările pentru zboruri internaționale
- `class passenger`: Moștenește d_booking și i_booking, stochează detalii pasager

## Dependențe

- C++ 11 sau superior

## Probleme Cunoscute (Known Issues)

1. **Validare insuficientă a inputului utilizatorilor**
   - **Problema:** Aplicația nu validează suficient inputul primit de la utilizatori, ceea ce poate duce la comportamente neașteptate sau chiar la crashuri.
   - **Soluție:** O soluție are fi să implementăm o validare riguroasă a datelor introduse de utilizatori, verificând tipul de date, lungimea, prezența caracterelor invalide etc.

2. **Lipsa tratării erorilor**
   - **Problema:** În anumite scenarii de eroare (de ex. eșecul deschiderii unui fișier), aplicația nu tratează corespunzător eroarea și se poate bloca sau închide brusc.
   - **Soluție:** Adăugăm tratarea corespunzătoare a erorilor folosind try-catch și afișați mesaje de eroare clare utilizatorului.

3. **Scurgeri de memorie**
   - **Problema:** Alocarea dinamică a memoriei (folosind 'new') fără eliberarea corespunzătoare (folosind 'delete') poate duce la scurgeri de memorie, în special în bucle sau în caz de excepții.
   - **Soluție:** Ne asigurăm că toate resursele alocate dinamic sunt corect eliberate. Folosiți smart pointers (unique_ptr, shared_ptr) unde este posibil.

## Vulnerabilități

1. **Criptare nesigură a parolelor**
   - **Problema:** Deși parolele sunt criptate folosind RSA, parametrii folosiți (valorile p și q) sunt prea mici pentru a oferi o securitate suficientă. Parolele ar putea fi sparte relativ ușor.
   - **Soluție:** Folosim valori p și q mai mari (de ex. numere prime de 1024 biți sau mai mult). Considerați folosirea unei librării mature de criptografie în loc de implementarea proprie.

2. **Stocarea nesecurizată a parolelor**
   - **Problema:** Parolele sunt stocate direct în fișiere text. Dacă un atacator obține acces la aceste fișiere, parolele pot fi compromise.
   - **Soluție:** Nu stocăm niciodată parolele în plain text. Stocați doar hash-uri securizate ale parolelor, folosind un algoritm puternic și sare (salt).

3. **Potențiale vulnerabilități de injecție**
   - **Problema:** Dacă datele introduse de utilizator sunt folosite direct în interogări SQL sau comenzi de sistem, aplicația poate fi vulnerabilă la atacuri de injecție.
   - **Soluție:** Folosim întotdeauna parametri sau proceduri stocate când construiți interogări SQL. Validați și curățați toate datele introduse de utilizator înainte de a le folosi.

## Contribuție

Contribuțiile sunt binevenite! Simțiți-vă liberi să deschideți un issue sau să trimiteți un pull request pentru a sugera îmbunătățiri sau a raporta probleme.
