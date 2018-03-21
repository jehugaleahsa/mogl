#pragma once
#ifndef MOGL_PRIMITIVES_TEXTURE_HPP
#define MOGL_PRIMITIVES_TEXTURE_HPP

#include "../common.hpp"

namespace mogl {
	namespace primitives {
		namespace texture {
			TextureUnit getActiveTexture() {
				GLint textureId;
				glGetIntegerv(GL_ACTIVE_TEXTURE, &textureId);
				return static_cast<TextureUnit>(textureId);
			}

			GLint getMaxCombinedTextureImageUnits() {
				GLint count;
				glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &count);
				return count;
			}

			constexpr void setActiveTexture(TextureUnit texture) {
				auto textureValue = toEnum(texture);
				glActiveTexture(textureValue);
			}
		}  // texture
	}  // primitives
}  // mogl

#endif  // MOGL_PRIMITIVES_TEXTURE_HPP