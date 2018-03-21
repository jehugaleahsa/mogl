#pragma once
#ifndef MOGL_PRIMITIVES_LINE_HPP
#define MOGL_PRIMITIVES_LINE_HPP

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace line {

			GLfloat getLineWidth() {
				GLfloat width;
				glGetFloatv(GL_LINE_WIDTH, &width);
				return width;
			}

			constexpr void setLineWidth(GLfloat width) {
				glLineWidth(width);
			}

			Range<GLfloat> getAliasedLineWidthRange() {
				GLfloat range[2];
				glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, range);
				return Range<GLfloat>{ range[0], range[1] };
			}

			Range<GLfloat> getSmoothLineWidthRange() {
				GLfloat range[2];
				glGetFloatv(GL_SMOOTH_LINE_WIDTH_RANGE, range);
				return Range<GLfloat>{ range[0], range[1] };
			}

			GLfloat getSmoothLineWidthGranularity() {
				GLfloat granularity;
				glGetFloatv(GL_SMOOTH_LINE_WIDTH_GRANULARITY, &granularity);
				return granularity;
			}
		}
	}
}

#endif  // MOGL_PRIMITIVES_LINE_HPP
