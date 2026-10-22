# 150 · Evaluate Reverse Polish Notation

**Patrón:** stack de operandos: los números entran al stack y cada operador saca los dos de arriba, opera y mete el resultado.

**Señal:** la expresión viene en orden postfijo (el operador va después de sus dos números) y cada operador usa "lo último que apareció". Lo último que entra es lo primero que se usa: eso es un stack.

**Tiempo/Espacio:** O(n) tiempo y O(n) espacio, con n = número de tokens; cada token entra y sale del stack una vez.

**Intento:** la lógica salió a la primera: saco primero `b` y luego `a`, así que `a - b` y `a / b` quedan en el orden correcto, y la `/` de C++ ya trunca hacia cero también con negativos. Antes de programar me di cuenta de que revisar si un token es número no sirve con `"-11"`, porque empieza con `-` igual que la resta; por eso reviso si es operador y todo lo demás va a `stoi`. Lo que falló fue C++: escribí un `switch` sobre `string` y en C++ el `switch` solo acepta enteros (`int`, `char`, enum), y me faltaron cinco `;`. Lo pasé a `if / else if` sin cambiar la lógica. Unos 6 minutos.

**Nota:** repito el mismo bloque de cuatro líneas en las cuatro ramas. Se puede detectar primero si el token es operador (`token.size() == 1 && !isdigit(token[0])`), sacar `b` y `a` una sola vez, y luego hacer `switch (token[0])`, que sí compila porque es un `char`.

**Repaso:** 2026-10-25