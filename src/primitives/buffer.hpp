#pragma once
#ifndef MOGL_PRIMITIVES_BUFFER_HPP
#define MOGL_PRIMITIVES_BUFFER_HPP

#include <memory>
#include <array>
#include <vector>
#include <iterator>

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace buffer {

			auto getActiveBuffer() {
				GLint bufferId;
				glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &bufferId);
				return static_cast<GLuint>(bufferId);
			}

			auto generate() {
				GLuint bufferId;
				glGenBuffers(1, &bufferId);
				return bufferId;
			}

			auto generate(int count) {
				std::vector<GLuint> data(count < 0 ? 0 : count);
				glGenBuffers(count, data.data());
				return data;
			}

			constexpr void reclaim(GLuint bufferId) {
				glDeleteBuffers(1, &bufferId);
			}

			constexpr void reclaim(std::vector<GLuint> const& bufferIds) {
				glDeleteBuffers(bufferIds.size(), bufferIds.data());
			}

			template <typename IT,
				typename = std::enable_if_t<std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<IT>::iterator_category>::value>>
			constexpr void reclaim(IT first, IT past) {
				glDeleteBuffers(past - first, &*first);
			}

			constexpr void bind(BufferType bufferType, GLuint bufferId) {
				auto typeValue = toEnum(bufferType);
				glBindBuffer(typeValue, bufferId);
			}

			constexpr void unbind(BufferType bufferType) {
				auto typeValue = toEnum(bufferType);
				glBindBuffer(typeValue, 0);
			}

			constexpr void bindBase(IndexedBufferType bufferType, GLuint index, GLuint bufferId) {
				auto typeValue = toEnum(bufferType);
				glBindBufferBase(typeValue, index, bufferId);
			}

			constexpr void unbindBase(IndexedBufferType bufferType, GLuint index) {
				auto typeValue = toEnum(bufferType);
				glBindBufferBase(typeValue, index, 0);
			}

			template <typename IT,
				typename = std::enable_if_t<std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<IT>::iterator_category>::value>>
			constexpr void bindBases(IndexedBufferType bufferType, GLuint index, IT first, IT past) {
				auto typeValue = toEnum(bufferType);
				glBindBuffersBase(typeValue, index, past - first, &*first);
			}

			constexpr void unbindBases(IndexedBufferType bufferType, GLuint index, GLsizei count) {
				auto typeValue = toEnum(bufferType);
				glBindBuffersBase(typeValue, index, count, nullptr);
			}

			constexpr void bindRange(IndexedBufferType bufferType, GLuint index, GLuint bufferId, GLintptr offset, GLsizeiptr size) {
				auto typeValue = toEnum(bufferType);
				glBindBufferRange(typeValue, index, bufferId, offset, size);
			}

			template <typename T>
			constexpr void bufferData(BufferType bufferType, int size, T const* data, BufferUsage usage) {
				auto typeValue = toEnum(bufferType);
				auto usageValue = toEnum(usage);
				glBufferData(typeValue, sizeof(T) * size, data, usageValue);
			}

			template <typename T>
			constexpr void bufferData(BufferType bufferType, std::vector<T> data, BufferUsage usage) {
				bufferData(bufferType, data.size(), data.data(), usage);
			}

		} // buffer
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_BUFFER_HPP