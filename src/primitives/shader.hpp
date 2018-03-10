#pragma once
#ifndef MOGL_PRIMITIVES_SHADER_HPP
#define MOGL_PRIMITIVES_SHADER_HPP

#include <memory>
#include <string>

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace shader {

			auto create(ShaderType shaderType) {
				auto typeValue = toEnum(shaderType);
				return glCreateShader(typeValue);
			}

			bool isShader(GLuint shaderId) {
				return glIsShader(shaderId) == GL_TRUE;
			}

			ShaderType getType(GLuint shaderId) {
				GLint type;
				glGetShaderiv(shaderId, GL_SHADER_TYPE, &type);
				return static_cast<ShaderType>(type);
			}

			bool isDeleted(GLuint shaderId) {
				GLint status;
				glGetShaderiv(shaderId, GL_DELETE_STATUS, &status);
				return status == GL_TRUE;
			}

			bool isCompiled(GLuint shaderId) {
				GLint status;
				glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
				return status == GL_TRUE;
			}

			auto getInformationLogLength(GLuint shaderId) {
				GLint length;
				glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
				return length == 0 ? 0 : length - 1;
			}

			auto getSourceLength(GLuint shaderId) {
				GLint length;
				glGetShaderiv(shaderId, GL_SHADER_SOURCE_LENGTH, &length);
				return length == 0 ? 0 : length - 1;
			}

			std::string getInformationLog(GLuint shaderId) {
				auto length = getInformationLogLength(shaderId);
				if (length == 0) {
					return std::string();
				}
				std::unique_ptr<char[]> data{ new char[length + 1] };
				glGetShaderInfoLog(shaderId, length + 1, nullptr, data.get());
				std::string result{ data.get() };
				return result;
			}

			void reclaim(GLuint shaderId) {
				glDeleteShader(shaderId);
			}

			void setSource(GLuint shaderId, char const* source) {
				glShaderSource(shaderId, 1, &source, nullptr);
			}

			void setSource(GLuint shaderId, std::string const& source) {
				char const* sourcePtr = source.c_str();
				GLint length = source.size();
				glShaderSource(shaderId, 1, &sourcePtr, &length);
			}

			void compile(GLuint shaderId) {
				glCompileShader(shaderId);
			}

		} // shader
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_SHADER_HPP