/**
* Copyright (c) 2006-2011 LOVE Development Team
* 
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* 
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
**/

#ifndef LOVE_GRAPHICS_OPENGL_SPRITE_BATCH_H
#define LOVE_GRAPHICS_OPENGL_SPRITE_BATCH_H

// C
#include <cstring>

// LOVE
#include <common/math.h>
#include <common/Object.h>
#include <common/Vector.h>
#include <common/Matrix.h>
#include <graphics/Drawable.h>
#include <graphics/Volatile.h>
#include <graphics/Color.h>

// OpenGL
#include "GLee.h"
#include <SDL/SDL_opengl.h>

namespace love
{
namespace graphics
{
namespace opengl
{
	// Forward declarations.
	class Image;
	class Quad;

	class SpriteBatch : public Drawable, public Volatile
	{
	private:

		Image * image;

		// Max number of sprites in the batch.
		int size;

		// The next free element.
		int next;

		GLuint vbo[2];

		// Vertex Buffer.
		vertex * vertices;

		// Index buffer.
		GLushort * indices;

		// The uage hint for the vertex buffer.
		int usage;
		int gl_usage;

		// If the buffer is locked, this pointer is nonzero.
		vertex * lockp;

		// Current color. This color, if present, will be applied to the next
		// added quad.
		Color * color;

	public:

		enum UsageHint
		{
			USAGE_DYNAMIC,
			USAGE_STATIC,
			USAGE_STREAM
		};

		SpriteBatch(Image * image, int size, int usage);
		virtual ~SpriteBatch();

		static bool isSupported();

		// Implements Volatile.
		bool loadVolatile();
		void unloadVolatile();

		void add(float x, float y, float a, float sx, float sy, float ox, float oy, float kx, float ky);
		void addq(Quad * quad, float x, float y, float a, float sx, float sy, float ox, float oy, float kx, float ky);
		void clear();

		void * lock();
		void unlock();

		void setImage(Image * newimage);

		/**
		 * Set the current color for this SpriteBatch. The geometry added
		 * after this call will use this color. Note that global color
		 * will not longer apply to the SpriteBatch if this is used.
		 *
		 * @param color The color to use for the following geometry.
		 */
		void setColor(const Color & color);

		/**
		 * Disable per-quad colors for this SpriteBatch. The next call to
		 * draw will use the global color for all sprites.
		 */
		void setColor();

		// Implements Drawable.
		void draw(float x, float y, float angle, float sx, float sy, float ox, float oy, float kx, float ky) const;

	private:

		void addv(const vertex * v);

		/**
		 * Set the color for vertices.
		 *
		 * @param v The vertices to set the color for. Must be an array of
		 *          of size 4.
		 * @param color The color to assign to each vertex.
		 */
		void setColorv(vertex * v, const Color & color);

	}; // SpriteBatch

} // opengl
} // graphics
} // love

#endif // LOVE_GRAPHICS_OPENGL_SPRITE_BATCH_H
