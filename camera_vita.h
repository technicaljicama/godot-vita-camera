/**************************************************************************/
/*  camera_vita.h                                                          */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef CAMERA_VITA_H
#define CAMERA_VITA_H

#include "servers/camera/camera_feed.h"
#include "servers/camera_server.h"
#include "core/os/thread.h"
#include "core/os/mutex.h"
#include "core/os/os.h"
#include "thirdparty/misc/yuv2rgb.h"


#include <psp2/camera.h>
#include <psp2/kernel/sysmem.h>


class CameraFeedVita : public CameraFeed {
private:
	Thread cam_thread;
	Mutex mutex;
	SceCameraInfo cam_info;

	void *img_data;
	PoolVector<uint8_t> img_pool;

	bool is_exit = false;

	static void update_image(void *p_udata);
protected:
public:
	CameraFeedVita();
	virtual ~CameraFeedVita();

	bool activate_feed();
	void deactivate_feed();
	void lock();
	void unlock();
};


class CameraVita : public CameraServer {
private:
	void add_active_cameras();
public:
	CameraVita();
	~CameraVita();
};

#endif // CAMERA_VITA_H
