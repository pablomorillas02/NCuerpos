//  Created by Antonio J. Rueda on 21/3/2024.
//  Copyright © 2024 Antonio J. Rueda.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef util_h
#define util_h

#include "../glad/glad/glad.h"

const unsigned SIM_ANCHO_TEXTURA_DATOS = 512;

float aleatorio(float min, float max);

void comprobarErrorShader(GLint status, GLint shader, const char *msg);

void comprobarErrorProgramaShader(GLint status, GLint program, const char *msg);

/** Crear programa con vertex y fragment shader
 @arg vs Código del vertex shader
 @arg fs Código del fragment shader */
GLuint crearProgramaShader(const char *vs, const char *fs);

/** Crear textura 2D cuadrada de vectores de vec2
 @arg tam Ancho y alto de la textura
 @arg datos Puntero al array de datos para inicializar textura (opcional)
 @return Identificador de textura */
GLuint crearTextura2DVec2(unsigned tam, const float *datos = 0);
    
#endif
