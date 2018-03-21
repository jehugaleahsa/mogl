#pragma once
#ifndef MOGL_PRIMITIVES_QUERY_HPP
#define MOGL_PRIMITIVES_QUERY_HPP

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace query {
			constexpr bool isQuery(GLuint queryId) {
				return glIsQuery(queryId) == GL_TRUE;
			}

			constexpr void beginConditionalRender(GLuint queryId, QueryMode mode) {
				auto modeValue = toEnum(mode);
				glBeginConditionalRender(queryId, modeValue);
			}

			constexpr void endConditionalRender() {
				glEndConditionalRender();
			}

			constexpr void beginQuery(QueryTarget target, GLuint queryId) {
				auto targetValue = toEnum(target);
				glBeginQuery(targetValue, queryId);
			}

			constexpr void endQuery(QueryTarget target) {
				auto targetValue = toEnum(target);
				glEndQuery(targetValue);
			}

			constexpr void beginQueryIndexed(QueryTarget target, GLuint index, GLuint queryId) {
				auto targetValue = toEnum(target);
				glBeginQueryIndexed(targetValue, index, queryId);
			}

			constexpr void endQueryIndexed(QueryTarget target, GLuint index) {
				auto targetValue = toEnum(target);
				glEndQueryIndexed(targetValue, index);
			}
		}  // query
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_QUERY_HPP