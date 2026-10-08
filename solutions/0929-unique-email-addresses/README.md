# 929 · Unique Email Addresses

**Patrón:** normalizar cada correo a una forma canónica y contar los únicos con sets. Yo agrupé por
dominio: `unordered_map<dominio, unordered_set<local>>`, y al final sumo los tamaños.

**Señal:** "¿cuántos son distintos?" con reglas de equivalencia (aquí: los puntos no cuentan y lo
que va después del `+` se ignora, solo en la parte local). Distintos bajo una regla = canonizar y
contar únicos.

**Tiempo/Espacio:** O(L) tiempo y espacio, con L = total de caracteres de todos los correos.

**Intento:** salió bien a la primera en lógica, ~27 min, pero con mucho tiempo en la API de C++:
`map[k]` crea la llave con un set vacío si no existe, `s.erase(pos)` borra hasta el final,
`erase(remove_if(...), end())` quita todos los puntos, y para recorrer un mapa no hay `.values()`:
se desempaca con `for (const auto& [dom, loc] : dir)`. Guardé `find` en `int` en vez de `size_t`;
funciona por accidente, porque `npos` se vuelve -1 y al comparar vuelve a `size_t`.

**Nota para la próxima:** el mapa sobra. Si la respuesta es un total, no hace falta agrupar: pegar
`local + "@" + dominio` en un solo `unordered_set` y regresar `size()`.

**Repaso:** 2026-10-10