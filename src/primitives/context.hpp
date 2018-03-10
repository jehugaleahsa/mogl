#pragma once
#ifndef MOGL_PRIMITIVES_CONTEXT_HPP
#define MOGL_PRIMITIVES_CONTEXT_HPP

#include <string>

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace context {
			namespace {
				ErrorType toErrorType(GLenum value) {
#ifdef MOGL_LOW_PROFILE
					return static_cast<ErrorType>(value);
#else
					auto type = static_cast<ErrorType>(value);
					switch (static_cast<ErrorType>(value)) {
						case ErrorType::NoError:
						case ErrorType::InvalidEnum:
						case ErrorType::InvalidValue:
						case ErrorType::InvalidOperation:
						case ErrorType::InvalidFramebufferOperation:
						case ErrorType::OutOfMemory:
						case ErrorType::StackUnderflow:
						case ErrorType::StackOverflow:
							return type;
						default: throw MoglException("Encountered an unknown error type.");
					}
#endif
				}
			}

			ErrorType getError() {
				auto error = glGetError();
				return toErrorType(error);
			}

			void clearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha = 1.0) {
				glClearColor(red, green, blue, alpha);
			}

			void clear(ClearFlags flags) {
				auto flagValues = toBitfield(flags);
				glClear(flagValues);
			}

			void setPolygonMode(Face face, PolygonMode mode) {
				auto faceValue = toEnum(face);
				auto modeValue = toEnum(mode);
				glPolygonMode(faceValue, modeValue);
			}

			void enable(Capability capability) {
				auto capabilityValue = toEnum(capability);
				glEnable(capabilityValue);
			}

			void disable(Capability capability) {
				auto capabilityValue = toEnum(capability);
				glDisable(capabilityValue);
			}

			bool isEnabled(Capability capability) {
				auto capabilityValue = toEnum(capability);
				return glIsEnabled(capabilityValue) == GL_TRUE;
			}

			void setDepthFunction(DepthFunction function) {
				auto functionValue = toEnum(function);
				glDepthFunc(functionValue);
			}

			void setBlendFunction(BlendScaleFactor sourceFactor, BlendScaleFactor destinationFactor) {
				auto sourceValue = toEnum(sourceFactor);
				auto destinationValue = toEnum(destinationFactor);
				glBlendFunc(sourceValue, destinationValue);
			}

			std::string getString(PropertyType property) {
				auto detailValue = toEnum(property);
				auto const* rawResult = glGetString(detailValue);
				auto const* result = reinterpret_cast<char const*>(rawResult);
				return std::string(result);
			}

			void drawElements(PrimitiveType primitiveType, GLsizei size, IndiceType indiceType, GLvoid const* indices) {
				auto elementTypeValue = toEnum(primitiveType);
				auto indiceTypeValue = toEnum(indiceType);
				glDrawElements(elementTypeValue, size, indiceTypeValue, indices);
			}

			void setViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
				glViewport(x, y, width, height);
			}

		} // context
	} // primitives
} // mogl

#endif  // MOGL_PRIMITIVES_CONTEXT_HPP