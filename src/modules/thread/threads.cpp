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

#include "threads.h"

#if LOVE_THREADS == LOVE_THREADS_POSIX
#  include "posix/threads.cpp"
#elif LOVE_THREADS == LOVE_THREADS_WIN32
#  include "win32/threads.cpp"
#elif LOVE_THREADS == LOVE_THREADS_SDL
#  include "sdl/threads.cpp"
#endif

namespace love
{
namespace thread
{

	const char* threadAPI() {
#if LOVE_THREADS == LOVE_THREADS_POSIX
		return "posix";
#elif LOVE_THREADS == LOVE_THREADS_WIN32
		return "win32";
#elif LOVE_THREADS == LOVE_THREADS_SDL
		return "sdl";
#else
		return "unknown"; // ?!?!?!
#endif
	}

} // namespace thread
} // namespace love