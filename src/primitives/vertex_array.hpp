#pragma once
#ifndef MOGL_PRIMTIVES_VERTEX_ARRAY_HPP
#define MOGL_PRIMTIVES_VERTEX_ARRAY_HPP

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace vertexArray {

			namespace {
				template <typename T> struct vertex_type_conversion;
				template <> struct vertex_type_conversion<GLbyte> { const static VertexType value = VertexType::Byte; };
				template <> struct vertex_type_conversion<GLdouble> { const static VertexType value = VertexType::Double; };
				template <> struct vertex_type_conversion<GLfloat> { const static VertexType value = VertexType::Float; };
				template <> struct vertex_type_conversion<GLint> { const static VertexType value = VertexType::Int; };
				template <> struct vertex_type_conversion<GLshort> { const static VertexType value = VertexType::Short; };
				template <> struct vertex_type_conversion<GLubyte> { const static VertexType value = VertexType::UnsignedByte; };
				template <> struct vertex_type_conversion<GLuint> { const static VertexType value = VertexType::UnsignedInt; };
				template <> struct vertex_type_conversion<GLushort> { const static VertexType value = VertexType::UnsignedShort; };

				template <typename ComponentType>
				constexpr void define(GLuint attributeId, GLint size, bool normalize, GLsizei stride, std::size_t offset) {
					auto typeValue = toEnum(vertex_type_conversion<ComponentType>::value);
					GLboolean normalizeValue = normalize ? GL_TRUE : GL_FALSE;
					glVertexAttribPointer(attributeId, size, typeValue, normalizeValue, stride, (GLvoid const*)offset);
				}
			}

			template <
				typename TVertex, 
				typename ComponentType, 
				GLint ComponentCount, 
				std::size_t ComponentOffset,
				typename = std::enable_if_t<std::is_standard_layout<TVertex>::value>>
			struct vertex_traits {
				using vertex_type = TVertex;
				using component_type = ComponentType;
				const static GLint component_size = ComponentCount;
				const static std::size_t component_offset = ComponentOffset;
			};

			template <typename Traits>
			constexpr void define(GLuint attributeId, bool normalize = false) {
				define<typename Traits::component_type>(attributeId, Traits::component_size, normalize, sizeof(typename Traits::vertex_type), Traits::component_offset);
			}

			constexpr void enable(GLuint attributeId) {
				glEnableVertexAttribArray(attributeId);
			}

			constexpr void disable(GLuint attributeId) {
				glDisableVertexAttribArray(attributeId);
			}

		}  // vertexArray
	}  // primtives
}  // mogl

#ifndef to_vertex_traits
#define to_vertex_traits(TVertex, member, memberType) ::mogl::primitives::vertexArray::vertex_traits<TVertex, memberType, sizeof(TVertex::member) / sizeof(memberType), offsetof(TVertex, member)>
#endif

#endif  // MOGL_PRIMTIVES_VERTEX_ARRAY_HPP
