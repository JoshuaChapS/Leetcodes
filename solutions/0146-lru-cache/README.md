# 146 · LRU Cache

**Patrón:** hash map + lista doblemente ligada. La lista guarda el orden de uso (el más reciente al frente) y el mapa guarda, para cada llave, un iterador a su nodo en la lista.

**Señal:** "get y put en O(1)" más "sacar el usado hace más tiempo". Encontrar en O(1) pide un hash map; mover y sacar de los extremos en O(1) pide una lista ligada. Ninguna de las dos alcanza sola.

**Tiempo/Espacio:** O(1) por operación y O(capacidad) de espacio.

**Intento:** mi primera idea fue un hash map y un `deque`, pero con un `get` de una llave que está en medio, borrarla del deque es O(n). La pieza que me faltaba: en el mapa no guardo solo el valor, guardo un iterador al nodo de la lista, y con él `list.erase(it)` es O(1) sin recorrer nada. Nunca había usado `std::list`: aprendí `push_front`, `back`, `pop_back`, `erase`, `begin` vs `front`, y que con un iterador se usa `->` en vez de `.`. Lo importante de `list` es que los iteradores guardados siguen sirviendo aunque se metan o saquen otros nodos. Con eso escribí `get` y `put` y salió a la primera. Cada nodo guarda `{llave, valor}` para poder borrar la llave del mapa cuando saco el más viejo con `back().first`. Me tomó unos 70 minutos, contando aprender la librería.

**Nota:** `used_` sobra porque `list.size()` es O(1). El "mover al frente" está repetido en `get` y `put`; se puede hacer con `list_.splice(list_.begin(), list_, dir_[key])`, que mueve el mismo nodo sin borrarlo y sin cambiar su iterador.

**Repaso:** 2026-11-04