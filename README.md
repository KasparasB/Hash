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
