#pragma once
#ifndef MOGL_PRIMITIVES_BUFFER_HPP
#define MOGL_PRIMITIVES_BUFFER_HPP

#include <memory>
#include <vector>

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace buffer {

			auto generate() {
				GLuint bufferId;
				glGenBuffers(1, &bufferId);
				return bufferId;
			}

			auto generate(int count) {
				if (count <= 0) {
					return std::vector<GLuint>{};
				}
				std::unique_ptr<GLuint[]> data{ new GLuint[count] };
				glGenBuffers(count, data.get());
				std::vector<GLuint> result{ data.get(), data.get() + count };
				return result;
			}

			void reclaim(GLuint bufferId) {
				glDeleteBuffers(1, &bufferId);
			}

			void reclaim(std::vector<GLuint> const& bufferIds) {
				glDeleteBuffers(bufferIds.size(), bufferIds.data());
			}

			void bind(BufferType bufferType, GLuint bufferId) {
				auto typeValue = toEnum(bufferType);
				glBindBuffer(typeValue, bufferId);
			}

			template <typename T>
			void bufferData(BufferType bufferType, int size, T const* data, BufferUsage usage) {
				auto typeValue = toEnum(bufferType);
				auto usageValue = toEnum(usage);
				glBufferData(typeValue, sizeof(T) * size, data, usageValue);
			}

			template <typename T>
			void bufferData(BufferType bufferType, std::vector<T> data, BufferUsage usage) {
				bufferData(bufferType, data.size(), data.data(), usage);
			}

		} // buffer
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_BUFFER_HPP