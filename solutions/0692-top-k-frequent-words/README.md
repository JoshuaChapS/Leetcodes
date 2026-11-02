# 692 · Top K Frequent Words

**Patrón:** contar con un hash map y quedarme con los k mejores en un heap de tamaño k, con un comparador propio para los empates.

**Señal:** "los k más frecuentes". Ordenar todo es O(m log m); un heap de tamaño k baja a O(m log k). El empate alfabético obliga a escribir el comparador.

**Tiempo/Espacio:** O(n + m log k) tiempo y O(m) espacio, con n = palabras y m = palabras distintas.

**Intento:** el enfoque fue mío desde el principio: contar, meter al heap y sacar cuando se pasa de k, y al final sacar todo y voltearlo. Lo que me costó fue el comparador. Mi primera versión del empate era `a.second >= b.second`, que estaba mal dos veces: decía que "banana" era mejor que "apple", y con `>=` dos elementos iguales regresaban `true`, que rompe la regla del comparador. Lo que no entendía es qué significa regresar `true`: quiere decir "a va antes que b". Con `sort` eso ordena de mejor a peor, y en un `priority_queue` el `top` es el que quedaría al final, o sea el peor, que es justo el que quiero tirar. Con esa explicación lo escribí y salió a la primera, en unos 18 minutos.

**Nota:** el comparador se puede escribir en dos líneas: si las frecuencias son distintas, `a.first > b.first`; si no, `a.second < b.second`. `pq.size() > k` compara `size_t` con `int`; con `(int)pq.size()` no hay aviso.

**Repaso:** 2026-11-05
