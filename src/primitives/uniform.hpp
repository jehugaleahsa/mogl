#pragma once
#ifndef MOGL_PRIMITIVES_UNIFORM_HPP
#define MOGL_PRIMITIVES_UNIFORM_HPP

namespace mogl {
	namespace primitives {
		namespace uniform {

			void setValue(GLint uniformId, GLint value1) {
				glUniform1i(uniformId, value1);
			}

			void setMatrix4(GLint uniformId, bool transpose, GLfloat * value) {
				auto transposeValue = transpose ? GL_TRUE : GL_FALSE;
				glUniformMatrix4fv(uniformId, 1, transposeValue, value);
			}

		}  // uniform
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_UNIFORM_HPP