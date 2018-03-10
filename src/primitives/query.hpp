#pragma once
#ifndef MOGL_PRIMITIVES_QUERY_HPP
#define MOGL_PRIMITIVES_QUERY_HPP

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace query {
			bool isQuery(GLuint queryId) {
				return glIsQuery(queryId) == GL_TRUE;
			}

			void beginConditionalRender(GLuint queryId, QueryMode mode) {
				auto modeValue = toEnum(mode);
				glBeginConditionalRender(queryId, modeValue);
			}

			void endConditionalRender() {
				glEndConditionalRender();
			}

			void beginQuery(QueryTarget target, GLuint queryId) {
				auto targetValue = toEnum(target);
				glBeginQuery(targetValue, queryId);
			}

			void endQuery(QueryTarget target) {
				auto targetValue = toEnum(target);
				glEndQuery(targetValue);
			}
		}  // query
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_QUERY_HPP