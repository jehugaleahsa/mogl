#pragma once
#ifndef MOGL_PRIMTIVES_VERTEX_ATTRIBUTE_ARRAY_HPP
#define MOGL_PRIMTIVES_VERTEX_ATTRIBUTE_ARRAY_HPP

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace vertexAttributeArray {

			void define(GLuint attributeId, GLint size, VertexType type, bool normalize, GLsizei stride, GLvoid const* offset) {
				auto typeValue = toEnum(type);
				GLboolean normalizeValue = normalize ? GL_TRUE : GL_FALSE;
				glVertexAttribPointer(attributeId, size, typeValue, normalizeValue, stride, offset);
			}

			void enable(GLuint attributeId) {
				glEnableVertexAttribArray(attributeId);
			}
		}  // vertexAttributeArray
	}  // primtives
}  // mogl

#endif  // MOGL_PRIMTIVES_VERTEX_ATTRIBUTE_ARRAY_HPP
