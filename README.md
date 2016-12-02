
# TETRIS
# Para hacer el juego usamos:
- Clases
- Encapsulamiento
- STL
- Punteros
- Memoria Dinamica
- Miniwin.h
- Time.h

# Mecanica del juego:
El jugador ha de colocar las piezas que le van apareciendo por la parte superior de la pantalla dentro de una tabla de m filas y n columnas. Se ha de intentar que las piezas que van cayendo se sitúen de tal forma que formen una línea con las que ya se encuentren en la tabla (con los fragmentos de otras piezas). En caso de que lo logremos, las porciones de las piezas que intervienen en la formación de la misma línea desaparecerán haciendo que todas las que se encuentren de esa línea, para arriba, desciendan una fila hacia abajo y por lo tanto, dejen más filas para que el jugador pueda manipular las piezas futuras). En el caso de que el jugador no logre hacer una línea la pieza quedará ubicada íntegramente, con lo que limitará el espacio de juego, haciendo que aumente la dificultad para colocar la pieza que venga a continuación.

# Movimiento: 
- Escape: salir del juego.
 ## Teclas de direccion:
- Abajo: desplazar hacia abajo:
- Izquierda: desplazamiento hacia la izquierda.
- Derecha: desplazamiento hacia la derecha.
- Arriba: Rotar la pieza.
# Problemas en la implementacion:
- La primera version del juego era sin punteros y cuando los implementamos hubo algunos problemas especialmente con las piezas.
- Tratamos de implementar herencia y polimorfismo pero carecia de sentido ya que solo heredaba coordenadas y tomamos la decisón de no implementarlos.
 


