# Hash

## Užduoties formuluotė

Sukurkite Jūsų (t.y. pabandykite neieškoti *hash* funkcijų pavyzdžių Internete) maišos (*hash*) funkciją (*hash* kodų generatorių), kuris pasižymėtų šiais *hash* funkcijoms keliamais reikalavimais:

1. Maišos funkcijos įėjimas (angl. *input*) gali būti <u>bet kokio dydžio</u> simbolių eilutė (angl. *string*).
2. Maišos funkcijos išėjimas (angl. *output*) visuomet yra <u>to paties fiksuoto dydžio</u> rezultatas.
3. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (angl. *input*'ui) išvedimas (angl. *output*'as) <u>visuomet</u> yra tas pats.
4. Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input reikšmėi yra apskaičiuojamas nesunkiai - efektyviai.
5. Iš funkcijos rezultato (*output*'o) praktiškai neįmanoma atgaminti įvedimo (*input*'o).
6. Praktiškai neįmanoma surasti tokių dviejų skirtingų argumentų (*input*'ų), kad jiems gautume tą patį *hash*'ą, t. y.,: *m1 != m2*, bet *h(m1) = h(m2)*.
7. Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės:

| Įvedimas (*input*) | Išvedimas (*hash'as* gautas iš  SHA256)                      |
| ------------------ | ------------------------------------------------------------ |
| lietuva            | f51f6afefb2616f48bbddeeada2d729244a00fa0817f9ceb5c5419aa04b31172 |
| Lietuva            | 5109820f748796128b8bafd3806d05511bc89ad77fc3cda960facf37a639bc7f |
| Lietuva!           | f4ac741acca7dd6f5f7e6fd1e382eca604a26ba21a83a6a2215d7be830a8faa6 |


### [v0.1](https://github.com/KasparasB/Duomenu_Apdorojimas/releases/tag/v0.1) papildymas

1. Maišos algoritmo input'as "teoriškai" priima bet kokio dydžio simbolių eilutę.
2. Maišos algortimo output'as yra fiksuoto dydžio 60 simbolių eilutė.
3. Maišos funkcija yra deterministinė ir tam pačiam input'ui visuomet gaunamas vienodas output'as.
4. Maišos funkcijos hash'as nėra apskaičiuojamas efektyviai.
5. Iš funkcijos rezultato beveik neįmanoma atgaminti įvedimo.
6. Įmanoma surasti du skirtingus input'us su vienodais output'ais.
7. Bent minimaliai pakeitus input'ą, output'as pasikeičia.


| Įvedimas (*input*) | Išvedimas (*hash'as* gautas iš  SHA256)                      |
| ------------------ | ------------------------------------------------------------ |
| Kasparas            | 150A0F32A662AA5E0D7132B05248985076F199DC25B09856BAACBE682BC949FDEF42D7549802308A580E0EF97DAAD74520C8 |
| kasparas            | 150A0F32A685AA5E0D7132B041BCA85076F199DC25B098391008AACBE682BC949FDEF458E80CD58308A580E0EF97DAAD7452 |
| kasparas!           | 75509ADE840F218A74953600AAF0C74978FB99A8B2FA6244E83A0FA836468DB859140B4A440EEE44B59A606239B287A40021 |

### Naudojimas

### Veikimas

1. Programa nuskaito simbolių eilutę.
2. Kiekvienas simbolių eilutės narys yra šifruojamas su prieš jį esančia raide.
3. Simbolių eilutė yra apverčiama (gaunamos dvi atskiros simbolių eilutės).
4. Simbolių eilutė yra dar kartą šifruojama (gaunamos trys simbolių eilutės).
5. Su trečiąją simbolių eilute yra šifruojama pirmoji, gauta eilutė išsaugoma ir su ja šifruojama antroji.
6. Procesas vyksta tol, kol simbolių kiekis tampa pakankamas hash'ui.
7. Simboliai paverčiami į ASCII skaičius.
8. ASCII skaičiai verčiami į šešioliktainius.

Programos veikimas yra neefektyvus, nemažai elementų yra "įhardcodinti". Programoje daug spragų. Kodas netvarkingas.

Dėl hash'o realizacijos spragų gaunamas per Konstitucijos output'as yra neteisingas: E1A70864C2F39F.



