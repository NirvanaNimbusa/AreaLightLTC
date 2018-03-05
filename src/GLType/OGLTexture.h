#pragma once

#include <GL/glew.h>
#include <string>
#include <GraphicsTypes.h>
#include <tools/Rtti.h>
#include <GLType/GraphicsTexture.h>

class OGLTexture final : public GraphicsTexture
{
	__DeclareSubInterface(OGLTexture, GraphicsTexture)
public:

	OGLTexture();
    virtual ~OGLTexture();

    bool create(const GraphicsTextureDesc& desc);
	bool create(const std::string& filename);
    bool create(GLint width, GLint height, GLenum target, GraphicsFormat format, GLuint levels, uint8_t* data, uint32_t size);
	void destroy();
	void bind(GLuint unit) const;
	void unbind(GLuint unit) const;
	void generateMipmap();
	void parameter(GLenum pname, GLint param);

    bool createFromFileGLI(const std::string& filename);
    bool createFromFileSTB(const std::string& filename);

    GLuint getTextureID() const noexcept;
    GLenum getFormat() const noexcept;

    const GraphicsTextureDesc& getGraphicsTextureDesc() const noexcept;

private:

	friend class OGLDevice;
	void setDevice(const GraphicsDevicePtr& device) noexcept;
	GraphicsDevicePtr getDevice() noexcept;

private:

	OGLTexture(const OGLTexture&) noexcept = delete;
	OGLTexture& operator=(const OGLTexture&) noexcept = delete;

private:

    GraphicsTextureDesc m_TextureDesc;

	GLuint m_TextureID;
	GLenum m_Target;
	GLenum m_Format;
	GraphicsDeviceWeakPtr m_Device;
};
