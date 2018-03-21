#pragma once
#ifndef MOGL_PRIMITIVES_PROGRAM_PIPELINE_HPP
#define MOGL_PRIMITIVES_PROGRAM_PIPELINE_HPP

#include "../common.hpp"

namespace mogl {
    namespace primitives {
        namespace programPipeline {

			GLuint getBoundPipeline() {
				GLint pipelineId;
				glGetIntegerv(GL_PROGRAM_PIPELINE_BINDING, &pipelineId);
				return static_cast<GLuint>(pipelineId);
			}

			constexpr void setActiveProgram(GLuint pipelineId, GLuint programId) {
				glActiveShaderProgram(pipelineId, programId);
			}

        }  // programPipeline
    }  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_PROGRAM_PIPELINE_HPP
