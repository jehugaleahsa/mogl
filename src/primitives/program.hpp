#pragma once
#ifndef MOGL_PRIMITIVES_PROGRAM_HPP
#define MOGL_PRIMITIVES_PROGRAM_HPP

#include <algorithm>
#include <memory>
#include <iterator>
#include <string>
#include <vector>

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace program {

			auto create() {
				auto result = glCreateProgram();
#ifndef MOGL_LOW_PROFILE
				if (result == 0) {
					throw MoglException("Could not create the shader program.");
				}
#endif
				return result;
			}

			bool isProgram(GLuint programId) {
				return glIsProgram(programId) == GL_TRUE;
			}

			bool isDeleted(GLuint programId) {
				GLint status;
				glGetProgramiv(programId, GL_DELETE_STATUS, &status);
				return status == GL_TRUE;
			}

			bool isLinked(GLuint programId) {
				GLint status;
				glGetProgramiv(programId, GL_LINK_STATUS, &status);
				return status == GL_TRUE;
			}

			bool isValid(GLuint programId) {
				GLint status;
				glGetProgramiv(programId, GL_VALIDATE_STATUS, &status);
				return status == GL_TRUE;
			}

			auto getInformationLogLength(GLuint programId) {
				GLint length;
				glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &length);
				return length == 0 ? 0 : length - 1;
			}

			auto getAttachedShaderCount(GLuint programId) {
				GLint count;
				glGetProgramiv(programId, GL_ATTACHED_SHADERS, &count);
				return count;
			}

			auto getActiveAttributeCount(GLuint programId) {
				GLint count;
				glGetProgramiv(programId, GL_ACTIVE_ATTRIBUTES, &count);
				return count;
			}

			auto getLongestAttributeNameLength(GLuint programId) {
				GLint length;
				glGetProgramiv(programId, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &length);
				return length == 0 ? 0 : length - 1;
			}

			auto getActiveUniformCount(GLuint programId) {
				GLint count;
				glGetProgramiv(programId, GL_ACTIVE_UNIFORMS, &count);
				return count;
			}

			auto getLongestUniformNameLength(GLuint programId) {
				GLint length;
				glGetProgramiv(programId, GL_ACTIVE_UNIFORM_MAX_LENGTH, &length);
				return length;
			}

			std::string getInformationLog(GLuint programId) {
				auto length = getInformationLogLength(programId);
				if (length == 0) {
					return std::string();
				}
				std::unique_ptr<char[]> data{ new char[length + 1] };
				glGetProgramInfoLog(programId, length + 1, nullptr, data.get());
				std::string result{ data.get() };
				return result;
			}

			std::vector<GLuint> getAttachedShaders(GLuint programId) {
				auto count = getAttachedShaderCount(programId);
				std::unique_ptr<GLuint[]> data{ new GLuint[count] };
				glGetAttachedShaders(programId, count, nullptr, data.get());
				std::vector<GLuint> result(data.get(), data.get() + count);
				return result;
			}

			bool isShaderAttached(GLuint programId, GLuint shaderId) {
				std::vector<GLuint> shaderIds{ getAttachedShaders(programId) };
				auto it = std::find_if(std::cbegin(shaderIds), std::cend(shaderIds), [=](GLuint nextId) {
					return shaderId == nextId;
				});
				return it != cend(shaderIds);
			}

			void attachShader(GLuint programId, GLuint shaderId) {
				glAttachShader(programId, shaderId);
			}
		}  // program
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_PROGRAM_HPP