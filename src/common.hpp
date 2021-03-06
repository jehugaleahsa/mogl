#pragma once
#ifndef MOGL_COMMON_HPP
#define MOGL_COMMON_HPP

#include <glad/glad.h>  // FIXME: comment this out

#include <type_traits>
#include <stdexcept>
#include <string>

namespace mogl {
	class MoglException : public std::runtime_error {
	public:
		MoglException(std::string const& message) : std::runtime_error{ message } {
		}
		MoglException(char const* message) : std::runtime_error{ message } {
		}
	};

	class Viewport {
		GLint x;
		GLint y;
		GLsizei width;
		GLsizei height;
	public:
		constexpr Viewport()
			: x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 } {
		}
		constexpr Viewport(GLsizei width, GLsizei height)
			: x{ 0 }, y{ 0 }, width{ width }, height{ height } {
		}
		constexpr Viewport(GLint x, GLint y, GLsizei width, GLsizei height)
			: x{ x }, y{ y }, width{ width }, height{ height } {
		}

		constexpr auto getX() const { return x; }
		constexpr auto getY() const { return y; }
		constexpr auto getWidth() const { return width; }
		constexpr auto getHeight() const { return height; }

		constexpr GLfloat getAspectRatio() const {
			return static_cast<GLfloat>(width) / height;
		}
	};

	template <typename T>
	class Range {
		T min;
		T max;
	public:
		constexpr Range(T min, T max) : min{ min }, max{ max } {}

		constexpr T getMin() const {
			return min;
		}

		constexpr T getMax() const {
			return max;
		}
	};

	class Color {
		GLfloat red;
		GLfloat green;
		GLfloat blue;
		GLfloat alpha;
	public:
		constexpr Color(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha = 1.0f)
			: red{ red }, green{ green }, blue{ blue }, alpha{ alpha } {
		}

		constexpr auto getRed() const {
			return red;
		}
		constexpr auto getGreen() const {
			return green;
		}
		constexpr auto getBlue() const {
			return blue;
		}
		constexpr auto getAlpha() const {
			return alpha;
		}
	};

	enum class ClearFlags : GLbitfield {
		ColorBuffer = GL_COLOR_BUFFER_BIT,
		DepthBuffer = GL_DEPTH_BUFFER_BIT,
#ifdef GL_ACCUM_BUFFER_BIT
		AccumulationBuffer = GL_ACCUM_BUFFER_BIT,
#endif
		StencilBuffer = GL_STENCIL_BUFFER_BIT
	};

	constexpr ClearFlags operator|(ClearFlags left, ClearFlags right) {
		auto combined = static_cast<GLbitfield>(left) | static_cast<GLbitfield>(right);
		return static_cast<ClearFlags>(combined);
	}

	constexpr ClearFlags operator&(ClearFlags left, ClearFlags right) {
		auto combined = static_cast<GLbitfield>(left) & static_cast<GLbitfield>(right);
		return static_cast<ClearFlags>(combined);
	}

	constexpr ClearFlags& operator|=(ClearFlags & left, ClearFlags right) {
		left = left | right;
		return left;
	}

	constexpr ClearFlags& operator&=(ClearFlags & left, ClearFlags right) {
		left = left & right;
		return left;
	}

	enum class Face {
		Front = GL_FRONT,
		Back = GL_BACK,
		FrontAndBack = GL_FRONT_AND_BACK
	};

	enum class PolygonMode : GLenum {
		Fill = GL_FILL,
		Line = GL_LINE
	};

	enum class Capability : GLenum {
		Blend = GL_BLEND,
		ClipDistance0 = GL_CLIP_DISTANCE0,
		ClipDistance1 = GL_CLIP_DISTANCE1,
		ClipDistance2 = GL_CLIP_DISTANCE2,
		ClipDistance3 = GL_CLIP_DISTANCE3,
		ClipDistance4 = GL_CLIP_DISTANCE4,
		ClipDistance5 = GL_CLIP_DISTANCE5,
		ClipDistance6 = GL_CLIP_DISTANCE6,
		ClipDistance7 = GL_CLIP_DISTANCE7,
		ColorLogicalOperation = GL_COLOR_LOGIC_OP,
		CullFace = GL_CULL_FACE,
		DepthClamp = GL_DEPTH_CLAMP,
		DebugOutput = GL_DEBUG_OUTPUT,
		DebugOutputSynchronous = GL_DEBUG_OUTPUT_SYNCHRONOUS,
		DepthTest = GL_DEPTH_TEST,
		Dither = GL_DITHER,
		FramebufferSRGB = GL_FRAMEBUFFER_SRGB,
		LineSmooth = GL_LINE_SMOOTH,
		Multisample = GL_MULTISAMPLE,
		PolygonSmooth = GL_POLYGON_SMOOTH,
		PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
		PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
		PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT,
		ProgramPointSize = GL_PROGRAM_POINT_SIZE,
		PrimitiveRestart = GL_PRIMITIVE_RESTART,
		SampleAlphaToCoverage = GL_SAMPLE_ALPHA_TO_COVERAGE,
		SampleAlphaToOne = GL_SAMPLE_ALPHA_TO_ONE,
		SampleCoverage = GL_SAMPLE_COVERAGE,
		SampleMask = GL_SAMPLE_MASK,
		ScissorTest = GL_SCISSOR_TEST,
		StencilTest = GL_STENCIL_TEST,
		TextureCubeMapSeamless = GL_TEXTURE_CUBE_MAP_SEAMLESS
	};

	enum class DepthFunction : GLenum {
		Never = GL_NEVER,
		Less = GL_LESS,
		Equal = GL_EQUAL,
		LessEqual = GL_LEQUAL,
		Greater = GL_GREATER,
		NotEqual = GL_NOTEQUAL,
		GreaterEqual = GL_GEQUAL,
		Always = GL_ALWAYS
	};

	enum class BlendScaleFactor : GLenum {
		Zero = GL_ZERO,
		One = GL_ONE,
		SourceColor = GL_SRC_COLOR,
		OneMinusSourceColor = GL_ONE_MINUS_SRC_COLOR,
		DestinationColor = GL_DST_COLOR,
		OneMinusDestinationColor = GL_ONE_MINUS_DST_COLOR,
		SourceAlpha = GL_SRC_ALPHA,
		OneMinusSourceAlpha = GL_ONE_MINUS_SRC_ALPHA,
		DestinationAlpha = GL_DST_ALPHA,
		OneMinusDestinationAlpha = GL_ONE_MINUS_DST_ALPHA,
		ConstantColor = GL_CONSTANT_COLOR,
		OneMinusConstantColor = GL_ONE_MINUS_CONSTANT_COLOR,
		ConstantAlpha = GL_CONSTANT_ALPHA,
		OneMinusConstantAlpha = GL_ONE_MINUS_CONSTANT_ALPHA,
		SourceAlphaSaturate = GL_SRC_ALPHA_SATURATE,
		Source1Color = GL_SRC1_COLOR,
		OneMinusSource1Color = GL_ONE_MINUS_SRC1_COLOR,
		Source1Alpha = GL_SRC1_ALPHA,
		OneMinusSource1Alpha = GL_ONE_MINUS_SRC1_ALPHA
	};

	enum class PropertyType : GLenum {
		Vendor = GL_VENDOR,
		Renderer = GL_RENDERER,
		Version = GL_VERSION,
		ShadingLanguageVersion = GL_SHADING_LANGUAGE_VERSION,
		Extensions = GL_EXTENSIONS
	};

	enum class ErrorType : GLenum {
		NoError = GL_NO_ERROR,
		InvalidEnum = GL_INVALID_ENUM,
		InvalidValue = GL_INVALID_VALUE,
		InvalidOperation = GL_INVALID_OPERATION,
		InvalidFramebufferOperation = GL_INVALID_FRAMEBUFFER_OPERATION,
		OutOfMemory = GL_OUT_OF_MEMORY,
		StackUnderflow = GL_STACK_UNDERFLOW,
		StackOverflow = GL_STACK_OVERFLOW
	};

	enum class QueryMode : GLenum {
		Wait = GL_QUERY_WAIT,
		NoWait = GL_QUERY_NO_WAIT,
		ByRegionWait = GL_QUERY_BY_REGION_WAIT,
		ByRegionNoWait = GL_QUERY_BY_REGION_NO_WAIT
	};

	enum class QueryTarget {
		SamplesPassed = GL_SAMPLES_PASSED,
		AnySamplesPassed = GL_ANY_SAMPLES_PASSED,
		AnySamplesPassedConservative = GL_ANY_SAMPLES_PASSED_CONSERVATIVE,
		PrimitivesGenerated = GL_PRIMITIVES_GENERATED,
		TransformFeedbackPrimitivesWritten = GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,
		TimeElapsed = GL_TIME_ELAPSED
	};

	enum class BufferType : GLenum {
		Array = GL_ARRAY_BUFFER,
		AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
		CopyRead = GL_COPY_READ_BUFFER,
		CopyWrite = GL_COPY_WRITE_BUFFER,
		DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
		DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
		ElementArray = GL_ELEMENT_ARRAY_BUFFER,
		PixelPack = GL_PIXEL_PACK_BUFFER,
		PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
		Query = GL_QUERY_BUFFER,
		ShaderStorage = GL_SHADER_STORAGE_BUFFER,
		Texture = GL_TEXTURE_BUFFER,
		TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
		Uniform = GL_UNIFORM_BUFFER
	};

	enum class IndexedBufferType : GLenum {
		AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
		ShaderStorage = GL_SHADER_STORAGE_BUFFER,
		TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
		Uniform = GL_UNIFORM_BUFFER
	};

	enum class BufferUsage : GLenum {
		StaticDraw = GL_STATIC_DRAW,
		StaticRead = GL_STATIC_READ,
		StaticCopy = GL_STATIC_COPY,
		DynamicDraw = GL_DYNAMIC_DRAW,
		DynamicRead = GL_DYNAMIC_READ,
		DynamicCopy = GL_DYNAMIC_COPY,
		StreamingDraw = GL_STREAM_DRAW,
		StreamingRead = GL_STREAM_READ,
		StreamingCopy = GL_STREAM_COPY
	};

	enum class PrimitiveType : GLenum {
		Points = GL_POINTS,
		LineStrip = GL_LINE_STRIP,
		LineLoop = GL_LINE_LOOP,
		Lines = GL_LINES,
		LineStripAdjaceny = GL_LINE_STRIP_ADJACENCY,
		LinesAdjacency = GL_LINES_ADJACENCY,
		TriangleStrip = GL_TRIANGLE_STRIP,
		TriangleFan = GL_TRIANGLE_FAN,
		Triangles = GL_TRIANGLES,
		TriangleStipAdjacency = GL_TRIANGLE_STRIP_ADJACENCY,
		TrianglesAdjacency = GL_TRIANGLES_ADJACENCY,
		Patches = GL_PATCHES
	};

	enum class IndiceType : GLenum {
		UnsignedByte = GL_UNSIGNED_BYTE,
		UnsignedShort = GL_UNSIGNED_SHORT,
		UnsignedInt = GL_UNSIGNED_INT
	};

	enum class VertexType : GLenum {
		Byte = GL_BYTE,
		UnsignedByte = GL_UNSIGNED_BYTE,
		Short = GL_SHORT,
		UnsignedShort = GL_UNSIGNED_SHORT,
		Int = GL_INT,
		UnsignedInt = GL_UNSIGNED_INT,
		HalfFloat = GL_HALF_FLOAT,
		Float = GL_FLOAT,
		Double = GL_DOUBLE,
		Fixed = GL_FIXED
	};

	enum class ShaderType : GLenum {
		Vertex = GL_VERTEX_SHADER,
		Geometry = GL_GEOMETRY_SHADER,
		Fragment = GL_FRAGMENT_SHADER
	};

	enum class TextureUnit : GLenum {
		Texture0 = GL_TEXTURE0,
		Texture1 = GL_TEXTURE1,
		Texture2 = GL_TEXTURE2,
		Texture3 = GL_TEXTURE3,
		Texture4 = GL_TEXTURE4,
		Texture5 = GL_TEXTURE5,
		Texture6 = GL_TEXTURE6,
		Texture7 = GL_TEXTURE7,
		Texture8 = GL_TEXTURE8,
		Texture9 = GL_TEXTURE9,
		Texture10 = GL_TEXTURE10,
		Texture11 = GL_TEXTURE11,
		Texture12 = GL_TEXTURE12,
		Texture13 = GL_TEXTURE13,
		Texture14 = GL_TEXTURE14,
		Texture15 = GL_TEXTURE15,
		Texture16 = GL_TEXTURE16,
		Texture17 = GL_TEXTURE17,
		Texture18 = GL_TEXTURE18,
		Texture19 = GL_TEXTURE19,
		Texture20 = GL_TEXTURE20,
		Texture21 = GL_TEXTURE21,
		Texture22 = GL_TEXTURE22,
		Texture23 = GL_TEXTURE23,
		Texture24 = GL_TEXTURE24,
		Texture25 = GL_TEXTURE25,
		Texture26 = GL_TEXTURE26,
		Texture27 = GL_TEXTURE27,
		Texture28 = GL_TEXTURE28,
		Texture29 = GL_TEXTURE29,
		Texture30 = GL_TEXTURE30,
		Texture31 = GL_TEXTURE31
	};

	enum class ObjectType : GLenum {
		Buffer = GL_BUFFER,
		Framebuffer = GL_FRAMEBUFFER,
		Program = GL_PROGRAM,
		ProgramPipeline = GL_PROGRAM_PIPELINE,
		Query = GL_QUERY,
		Renderbuffer = GL_RENDERBUFFER,
		Sampler = GL_SAMPLER,
		Shader = GL_SHADER,
		Texture = GL_TEXTURE,
		TransformFeedback = GL_TRANSFORM_FEEDBACK,
		VertexArray = GL_VERTEX_ARRAY
	};

	enum class TransformFeedbackPrimitiveType : GLenum {
		Points = GL_POINTS,
		Lines = GL_LINES,
		Triangles = GL_TRIANGLES
	};

	constexpr GLbitfield toBitfield(ClearFlags flags) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLbitfield>(flags);
#else
		GLbitfield result = 0;
		if ((flags & ClearFlags::ColorBuffer) == ClearFlags::ColorBuffer) {
			result |= static_cast<GLbitfield>(ClearFlags::ColorBuffer);
		}
		if ((flags & ClearFlags::DepthBuffer) == ClearFlags::DepthBuffer) {
			result |= static_cast<GLbitfield>(ClearFlags::DepthBuffer);
		}
#ifdef GL_ACCUM_BUFFER_BIT
		if ((flags & ClearFlags::AccumulationBuffer) == ClearFlags::AccumulationBuffer) {
			result |= static_cast<GLbitfield>(ClearFlags::AccumulationBuffer);
		}
#endif
		if ((flags & ClearFlags::StencilBuffer) == ClearFlags::StencilBuffer) {
			result |= static_cast<GLbitfield>(ClearFlags::StencilBuffer);
		}
		if (static_cast<GLbitfield>(flags) != result) {
			throw MoglException("Encountered an unknown clear flag.");
		}
		return result;
#endif
	}

	constexpr GLenum toEnum(Face value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case Face::Front:
			case Face::Back:
			case Face::FrontAndBack:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown face.");
		}
#endif
	}

	constexpr GLenum toEnum(PolygonMode value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case PolygonMode::Line:
			case PolygonMode::Fill:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown polygon mode.");
		}
#endif
	}

	constexpr GLenum toEnum(Capability value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case Capability::Blend:
			case Capability::ClipDistance0:
			case Capability::ClipDistance1:
			case Capability::ClipDistance2:
			case Capability::ClipDistance3:
			case Capability::ClipDistance4:
			case Capability::ClipDistance5:
			case Capability::ClipDistance6:
			case Capability::ClipDistance7:
			case Capability::ColorLogicalOperation:
			case Capability::CullFace:
			case Capability::DepthClamp:
			case Capability::DebugOutput:
			case Capability::DebugOutputSynchronous:
			case Capability::DepthTest:
			case Capability::Dither:
			case Capability::FramebufferSRGB:
			case Capability::LineSmooth:
			case Capability::Multisample:
			case Capability::PolygonSmooth:
			case Capability::PolygonOffsetFill:
			case Capability::PolygonOffsetLine:
			case Capability::PolygonOffsetPoint:
			case Capability::ProgramPointSize:
			case Capability::PrimitiveRestart:
			case Capability::SampleAlphaToCoverage:
			case Capability::SampleAlphaToOne:
			case Capability::SampleCoverage:
			case Capability::SampleMask:
			case Capability::ScissorTest:
			case Capability::StencilTest:
			case Capability::TextureCubeMapSeamless:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown capability.");
		}
#endif
	}

	constexpr GLenum toEnum(DepthFunction value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case DepthFunction::Never:
			case DepthFunction::Less:
			case DepthFunction::Equal:
			case DepthFunction::LessEqual:
			case DepthFunction::Greater:
			case DepthFunction::NotEqual:
			case DepthFunction::GreaterEqual:
			case DepthFunction::Always:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown depth function.");
		}
#endif
	}

	constexpr GLenum toEnum(BlendScaleFactor value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case BlendScaleFactor::Zero:
			case BlendScaleFactor::One:
			case BlendScaleFactor::SourceColor:
			case BlendScaleFactor::OneMinusSourceColor:
			case BlendScaleFactor::DestinationColor:
			case BlendScaleFactor::OneMinusDestinationColor:
			case BlendScaleFactor::SourceAlpha:
			case BlendScaleFactor::OneMinusSourceAlpha:
			case BlendScaleFactor::DestinationAlpha:
			case BlendScaleFactor::OneMinusDestinationAlpha:
			case BlendScaleFactor::ConstantColor:
			case BlendScaleFactor::OneMinusConstantColor:
			case BlendScaleFactor::ConstantAlpha:
			case BlendScaleFactor::OneMinusConstantAlpha:
			case BlendScaleFactor::SourceAlphaSaturate:
			case BlendScaleFactor::Source1Color:
			case BlendScaleFactor::OneMinusSource1Color:
			case BlendScaleFactor::Source1Alpha:
			case BlendScaleFactor::OneMinusSource1Alpha:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown blending function.");
		}
#endif
	}

	constexpr GLenum toEnum(PropertyType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case PropertyType::Vendor:
			case PropertyType::Renderer:
			case PropertyType::Version:
			case PropertyType::ShadingLanguageVersion:
			case PropertyType::Extensions:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown connection detail.");
		}
#endif
	}

	constexpr GLenum toEnum(PrimitiveType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case PrimitiveType::Points:
			case PrimitiveType::LineStrip:
			case PrimitiveType::LineLoop:
			case PrimitiveType::Lines:
			case PrimitiveType::LineStripAdjaceny:
			case PrimitiveType::LinesAdjacency:
			case PrimitiveType::TriangleStrip:
			case PrimitiveType::TriangleFan:
			case PrimitiveType::Triangles:
			case PrimitiveType::TriangleStipAdjacency:
			case PrimitiveType::TrianglesAdjacency:
			case PrimitiveType::Patches:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown primitive type.");
		}
#endif
	}

	constexpr GLenum toEnum(IndiceType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case IndiceType::UnsignedByte:
			case IndiceType::UnsignedShort:
			case IndiceType::UnsignedInt:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown indice type.");
		}
#endif
	}

	constexpr GLenum toEnum(QueryMode value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case QueryMode::Wait:
			case QueryMode::NoWait:
			case QueryMode::ByRegionWait:
			case QueryMode::ByRegionNoWait:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown query by region type.");
		}
#endif
	}

	constexpr GLenum toEnum(QueryTarget value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case QueryTarget::SamplesPassed:
			case QueryTarget::AnySamplesPassed:
			case QueryTarget::AnySamplesPassedConservative:
			case QueryTarget::PrimitivesGenerated:
			case QueryTarget::TransformFeedbackPrimitivesWritten:
			case QueryTarget::TimeElapsed:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown query target.");
		}
#endif
	}

	constexpr GLenum toEnum(BufferType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case BufferType::Array:
			case BufferType::AtomicCounter:
			case BufferType::CopyRead:
			case BufferType::CopyWrite:
			case BufferType::DispatchIndirect:
			case BufferType::DrawIndirect:
			case BufferType::ElementArray:
			case BufferType::PixelPack:
			case BufferType::PixelUnpack:
			case BufferType::Query:
			case BufferType::ShaderStorage:
			case BufferType::Texture:
			case BufferType::TransformFeedback:
			case BufferType::Uniform:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown buffer type.");
		}
#endif
	}

	constexpr GLenum toEnum(IndexedBufferType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case IndexedBufferType::AtomicCounter:
			case IndexedBufferType::ShaderStorage:
			case IndexedBufferType::TransformFeedback:
			case IndexedBufferType::Uniform:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown buffer type.");
	}
#endif
	}

	constexpr GLenum toEnum(BufferUsage value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case BufferUsage::StaticDraw:
			case BufferUsage::StaticRead:
			case BufferUsage::StaticCopy:
			case BufferUsage::DynamicDraw:
			case BufferUsage::DynamicRead:
			case BufferUsage::DynamicCopy:
			case BufferUsage::StreamingDraw:
			case BufferUsage::StreamingRead:
			case BufferUsage::StreamingCopy:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknow draw type.");
		}
#endif
	}

	constexpr GLenum toEnum(VertexType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case VertexType::Byte:
			case VertexType::UnsignedByte:
			case VertexType::Short:
			case VertexType::UnsignedShort:
			case VertexType::Int:
			case VertexType::UnsignedInt:
			case VertexType::HalfFloat:
			case VertexType::Float:
			case VertexType::Double:
			case VertexType::Fixed:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown vertex type.");
		}
#endif
	}

	constexpr GLenum toEnum(ShaderType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case ShaderType::Vertex:
			case ShaderType::Geometry:
			case ShaderType::Fragment:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown shader type.");
		}
#endif
	}

	constexpr GLenum toEnum(TextureUnit value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case TextureUnit::Texture0:
			case TextureUnit::Texture1:
			case TextureUnit::Texture2:
			case TextureUnit::Texture3:
			case TextureUnit::Texture4:
			case TextureUnit::Texture5:
			case TextureUnit::Texture6:
			case TextureUnit::Texture7:
			case TextureUnit::Texture8:
			case TextureUnit::Texture9:
			case TextureUnit::Texture10:
			case TextureUnit::Texture11:
			case TextureUnit::Texture12:
			case TextureUnit::Texture13:
			case TextureUnit::Texture14:
			case TextureUnit::Texture15:
			case TextureUnit::Texture16:
			case TextureUnit::Texture17:
			case TextureUnit::Texture18:
			case TextureUnit::Texture19:
			case TextureUnit::Texture20:
			case TextureUnit::Texture21:
			case TextureUnit::Texture22:
			case TextureUnit::Texture23:
			case TextureUnit::Texture24:
			case TextureUnit::Texture25:
			case TextureUnit::Texture26:
			case TextureUnit::Texture27:
			case TextureUnit::Texture28:
			case TextureUnit::Texture29:
			case TextureUnit::Texture30:
			case TextureUnit::Texture31:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown texture unit.");
		}
#endif
	}

	constexpr GLenum toEnum(ObjectType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case ObjectType::Buffer:
			case ObjectType::Framebuffer:
			case ObjectType::Program:
			case ObjectType::ProgramPipeline:
			case ObjectType::Query:
			case ObjectType::Renderbuffer:
			case ObjectType::Sampler:
			case ObjectType::Shader:
			case ObjectType::Texture:
			case ObjectType::TransformFeedback:
			case ObjectType::VertexArray:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown object type.");
		}
#endif
	}

	constexpr GLenum toEnum(TransformFeedbackPrimitiveType value) {
#ifdef MOGL_LOW_PROFILE
		return static_cast<GLenum>(value);
#else
		switch (value) {
			case TransformFeedbackPrimitiveType::Points:
			case TransformFeedbackPrimitiveType::Lines:
			case TransformFeedbackPrimitiveType::Triangles:
				return static_cast<GLenum>(value);
			default: throw MoglException("Encountered an unknown primitive type.");
		}
#endif
	}
}

#endif  // MOGL_PRIMITIVES_COMMON_HPP
