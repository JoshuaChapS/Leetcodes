# 937. Reorder Data in Log Files

**Patrón:** partición en dos grupos + `sort` con comparador de desempate.

**Señal:** dos categorías con reglas de orden distintas, y una de ellas conserva su
orden original. Eso se resuelve partiendo en dos vectores y ordenando solo uno —
no hace falta `stable_sort` si el grupo que no se toca nunca entra al `sort`.
Y "empata por X, desempata por Y" siempre es un comparador en cascada.

**Tiempo/Espacio:** O(n·m log n) tiempo, O(n·m) espacio, con n = número de logs y
m = largo de un log. El log n son las comparaciones del sort; la m es que cada
comparación construye dos `substr`, o sea copia.

**Intento:**
Tres bugs, y los tres fueron de leer, no de programar.

Clasifiqué con `log.substr(0,3) == "let"`. En el ejemplo del enunciado los
identificadores se llaman `let1` y `dig1`, así que funcionaba — con
`["a1 9 2 3 1", "g1 act car", ...]` no clasifica nada y devuelve la entrada
intacta. Leí los datos de ejemplo en vez del contrato: la categoría la define el
primer carácter después del espacio, no el nombre.

Después ordené al revés. El comparador de `sort` contesta "¿va x ANTES que y?",
y yo devolvía `true` cuando `a` era mayor.

Y lo tercero: escribí a mano ~40 líneas de comparación lexicográfica que
`std::string` ya tiene en su `operator<`. Media hora antes había preguntado
justo cómo compara `<` dos strings de distinto tamaño. Todo eso es:

    if (cx != cy) return cx < cy;
    return idX < idY;

Menos código no solo es más corto: con cuatro bucles casi idénticos, invertir la
dirección significa cambiar ocho signos y dejarte uno rompe el strict weak
ordering, que no da resultado mal ordenado — da segfault.

**Repaso:** 12 sep 2026