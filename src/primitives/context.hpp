#pragma once
#ifndef MOGL_PRIMITIVES_CONTEXT_HPP
#define MOGL_PRIMITIVES_CONTEXT_HPP

#include <string>

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace context {
			namespace {
				constexpr ErrorType toErrorType(GLenum value) {
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

			constexpr ErrorType getError() {
				auto error = glGetError();
				return toErrorType(error);
			}

			constexpr void clearColor(Color color) {
				glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
			}

			constexpr void clear(ClearFlags flags) {
				auto flagValues = toBitfield(flags);
				glClear(flagValues);
			}

			constexpr void setPolygonMode(Face face, PolygonMode mode) {
				auto faceValue = toEnum(face);
				auto modeValue = toEnum(mode);
				glPolygonMode(faceValue, modeValue);
			}

			constexpr void enable(Capability capability) {
				auto capabilityValue = toEnum(capability);
				glEnable(capabilityValue);
			}

			constexpr void disable(Capability capability) {
				auto capabilityValue = toEnum(capability);
				glDisable(capabilityValue);
			}

			constexpr bool isEnabled(Capability capability) {
				auto capabilityValue = toEnum(capability);
				return glIsEnabled(capabilityValue) == GL_TRUE;
			}

			constexpr void setDepthFunction(DepthFunction function) {
				auto functionValue = toEnum(function);
				glDepthFunc(functionValue);
			}

			constexpr void setBlendFunction(BlendScaleFactor sourceFactor, BlendScaleFactor destinationFactor) {
				auto sourceValue = toEnum(sourceFactor);
				auto destinationValue = toEnum(destinationFactor);
				glBlendFunc(sourceValue, destinationValue);
			}

			constexpr void setBlendColor(Color color) {
				glBlendColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
			}

			Color getBlendColor() {
				GLfloat parts[4];
				glGetFloatv(GL_BLEND_COLOR, parts);
				return Color{ parts[0], parts[1], parts[2], parts[3] };
			}

			inline std::string getString(PropertyType property) {
				auto detailValue = toEnum(property);
				GLubyte const* rawResult = glGetString(detailValue);
				char const* result = reinterpret_cast<char const*>(rawResult);
				return std::string{ result };
			}

			constexpr void drawElements(PrimitiveType primitiveType, GLsizei size, IndiceType indiceType, GLvoid const* indices) {
				auto elementTypeValue = toEnum(primitiveType);
				auto indiceTypeValue = toEnum(indiceType);
				glDrawElements(elementTypeValue, size, indiceTypeValue, indices);
			}

			constexpr void setViewport(Viewport viewPort) {
				glViewport(viewPort.getX(), viewPort.getY(), viewPort.getWidth(), viewPort.getHeight());
			}

			Viewport const getViewport() {
				GLint coordinates[4];
				glGetIntegerv(GL_VIEWPORT, coordinates);
				return mogl::Viewport(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
			}

		} // context
	} // primitives
} // mogl

#endif  // MOGL_PRIMITIVES_CONTEXT_HPP