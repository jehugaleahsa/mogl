#pragma once
#ifndef MOGL_PRIMITIVES_TRANSFORM_FEEDBACK_HPP
#define MOGL_PRIMITIVES_TRANSFORM_FEEDBACK_HPP

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace transformFeedback {

			constexpr void begin(TransformFeedbackPrimitiveType primitiveType) {
				auto typeValue = toEnum(primitiveType);
				glBeginTransformFeedback(typeValue);
			}

			constexpr void end() {
				glEndTransformFeedback();
			}

		}  // transformFeedback
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_TRANSFORM_FEEDBACK_HPP
