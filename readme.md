Projekt - gra w statki.

Uruchomienie gry:

    make - aby skompilować program

    ./game.out - aby uruchomić grę

Uwagi:

    Po uruchomieniu gry nastąpi losowe generowanie planszy gracza i planszy przeciwnika. Ładowanie 
    plansz może potrwać nawet kilkanaście sekund. W wypadku wystąpienia błędy "segmentation fault",
    proszę  uruchomić grę ponownie.

Instrukcja:

    Po załadowaniu planszy pojawi się możliwość wykonania strzału w planszę gracza Puste pola 
    oznaczone są numerem 0. Pola, na których są statki oznaczone są numerem 1 Trafione 
    statki zmieniają numer z 1 na 8. Statki na planszy są 4. Ich rozmiar to 2,3,4,5 kratek. 
    Proszę podać odpowiednio numer rzędu i kolomny z przedziału [0 - 9]. W przypadku celnego 
    trafienia pojawi się odpowiedni komunikat, w przeciwnym razie nie pojawi się żaden napis. 
    Następnie ruch wykonuje komputer. W przypadku udanego trafienia pojawi się komunikat 
    o trafieniu naszego statku przez przeciwnika, a  statek zmieni numer z 1 na 8.Wygrywa ta
    strona, która pierwsza zestrzeli wszystkie statki przeciwnika.

Program:

Klasa Ships:
    Klasa Ships odpowiada za statki. Do konstruktora przekazywany jest roamiar statku i tablica,
    na której będzie umieszczony.
    
    Funkcje:
    
    position:

    Funkcja odpowiada za umieszczenie statku na planszy w sposób losowy. Losowane jest row i col z
    przedziału od 0 do 9
    za pomocą funkcji rand. Zmienna opt odpowiada za sposób w jaki budowane będą statki. 0 to wzdłuż wierszy. 1 to wzdłuż kolumn.W przypadku nie spełnienia jednego z warunków np nachodzenia na inny statek lub wyjścia poza planszę funkcja uruchamiana jest jeszcze raz.

    exist:
    Sprawdza czy statek jeszcze istnieje. Jeśli tak, funkcja zwraca 0, jeśli nie, zwraca -1.

Klasa Enemy:
    Klasa odpowiada za ruch komputera.

    move:
    Odpowiada za strzał komputera. Losowana jest pozycja na planszy za pomocą funkcji rand.
    W przypadku pomyślnego strzału przy kolejnym wywolaniu funkcji losowana jest pozycja w pobliżu tej trafionej.

Klasa Board:
    W konstruktorze tworzona jest plansza (dynamiczna tablica) i tworzone są statki. Klasa Board odpowiada
    za planszę. Destruktor usuwa planszę.

    Funkcje:

    display: odpowiada za wyświetlenie planszy.
    setships: odpowiada za rozmieszczenie wszystkich statków na planszy za pomocą funkcji position z klasy
    Ships.
    defeat: sprawdza czy statki jeszcze istnieją, jeśli nie to funckja zwraca 1 i gra zostaje zakończona.
    shot: odpowiada za możliwość strzału w statek przeciwnika.



    
