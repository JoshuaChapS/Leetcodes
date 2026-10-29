# 53 · Maximum Subarray

**Patrón:** Kadane: `sum` = la mejor suma de un subarreglo que termina en i. En cada paso, o empiezo de nuevo en `nums[i]` o sigo sumando, lo que dé más.

**Señal:** "subarreglo contiguo con la suma máxima". La mejor suma que termina en i solo depende de la que termina en i − 1, así que basta una pasada guardando ese valor.

**Tiempo/Espacio:** O(n) tiempo y O(1) espacio, con n = tamaño del arreglo. La fuerza bruta, probar todos los subarreglos, es O(n²).

**Intento:** la primera versión tenía dos errores. Solo actualizaba `ans` cuando reiniciaba la suma, así que con `[-2,1,-3,4,-1,2,1,-5,4]` el 6 llegaba por el `else` y nunca se guardaba: daba 4. Y reiniciaba cuando `nums[i] > sum`, que está mal: con `[3,-1,4]` tiraba el 2 que llevaba y daba 4 en vez de 6. Llevar algo positivo nunca estorba; solo conviene empezar de nuevo cuando lo que llevo es negativo. Lo arreglé con `nums[i] > sum + nums[i]`, que es lo mismo que `sum < 0`, y al final lo simplifiqué a `sum = max(nums[i], sum + nums[i])`. Necesité dos pistas: el recorrido donde se perdía el 6 y el contraejemplo. Unos 15 minutos.

**Nota:** si te piden también los índices del subarreglo, guardas dónde empieza la suma actual cada vez que reinicias, y lo copias junto con `ans` cuando mejora.

**Repaso:** 2026-11-01