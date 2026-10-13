# 853 · Car Fleet

**Patrón:** ordenar por posición y barrer desde el que va más adelante, comparando tiempos de
llegada.

**Señal:** "los de atrás no pueden rebasar", "se juntan y avanzan al paso del de adelante". Si el
orden físico importa y nadie rebasa, se ordena por posición y cada elemento solo depende del grupo
que tiene enfrente.

**Tiempo/Espacio:** O(n log n) tiempo por el `sort`, O(n) espacio para los pares y los tiempos.

**Intento:** en un simulacro de 90 min. A los ~24 min me atoré y me pareció demasiado difícil
para un OA; me cambié al 1170, lo terminé y regresé. La idea: ordenar por posición, calcular cuánto
tarda cada coche en llegar (`(target − pos) / speed`) y recorrer de adelante hacia atrás. Un coche
que llegaría antes o al mismo tiempo que el líder de la flota que tiene enfrente se le pega y no
cuenta como flota nueva; si tarda más, se vuelve el nuevo líder. Salió bien a la primera; terminé
los dos problemas en ~74 de los 90 min.

**Nota:** usé `float` para los tiempos. Pasó, pero `float` guarda ~7 dígitos y con posiciones y
velocidades de hasta 10⁶ dos tiempos iguales pueden salir distintos por redondeo: `double` es lo
seguro.

**Repaso:** 2026-10-15