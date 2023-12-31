/* Generated by wayland-scanner 1.22.0 */

#ifndef EXT_WORKSPACE_UNSTABLE_V1_SERVER_PROTOCOL_H
#define EXT_WORKSPACE_UNSTABLE_V1_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_ext_workspace_unstable_v1 The ext_workspace_unstable_v1 protocol
 * @section page_ifaces_ext_workspace_unstable_v1 Interfaces
 * - @subpage page_iface_zext_workspace_manager_v1 - list and control workspaces
 * - @subpage page_iface_zext_workspace_group_handle_v1 - a workspace group assigned to a set of outputs
 * - @subpage page_iface_zext_workspace_handle_v1 - a workspace handing a group of surfaces
 * @section page_copyright_ext_workspace_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2019 Christopher Billington
 * Copyright © 2020 Ilia Bozhinov
 *
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 * </pre>
 */
struct wl_output;
struct zext_workspace_group_handle_v1;
struct zext_workspace_handle_v1;
struct zext_workspace_manager_v1;

#ifndef ZEXT_WORKSPACE_MANAGER_V1_INTERFACE
#define ZEXT_WORKSPACE_MANAGER_V1_INTERFACE
/**
 * @page page_iface_zext_workspace_manager_v1 zext_workspace_manager_v1
 * @section page_iface_zext_workspace_manager_v1_desc Description
 *
 * Workspaces, also called virtual desktops, are groups of surfaces. A
 * compositor with a concept of workspaces may only show some such groups of
 * surfaces (those of 'active' workspaces) at a time. 'Activating' a
 * workspace is a request for the compositor to display that workspace's
 * surfaces as normal, whereas the compositor may hide or otherwise
 * de-emphasise surfaces that are associated only with 'inactive' workspaces.
 * Workspaces are grouped by which sets of outputs they correspond to, and
 * may contain surfaces only from those outputs. In this way, it is possible
 * for each output to have its own set of workspaces, or for all outputs (or
 * any other arbitrary grouping) to share workspaces. Compositors may
 * optionally conceptually arrange each group of workspaces in an
 * N-dimensional grid.
 *
 * The purpose of this protocol is to enable the creation of taskbars and
 * docks by providing them with a list of workspaces and their properties,
 * and allowing them to activate and deactivate workspaces.
 *
 * After a client binds the zext_workspace_manager_v1, each workspace will be
 * sent via the workspace event.
 * @section page_iface_zext_workspace_manager_v1_api API
 * See @ref iface_zext_workspace_manager_v1.
 */
/**
 * @defgroup iface_zext_workspace_manager_v1 The zext_workspace_manager_v1 interface
 *
 * Workspaces, also called virtual desktops, are groups of surfaces. A
 * compositor with a concept of workspaces may only show some such groups of
 * surfaces (those of 'active' workspaces) at a time. 'Activating' a
 * workspace is a request for the compositor to display that workspace's
 * surfaces as normal, whereas the compositor may hide or otherwise
 * de-emphasise surfaces that are associated only with 'inactive' workspaces.
 * Workspaces are grouped by which sets of outputs they correspond to, and
 * may contain surfaces only from those outputs. In this way, it is possible
 * for each output to have its own set of workspaces, or for all outputs (or
 * any other arbitrary grouping) to share workspaces. Compositors may
 * optionally conceptually arrange each group of workspaces in an
 * N-dimensional grid.
 *
 * The purpose of this protocol is to enable the creation of taskbars and
 * docks by providing them with a list of workspaces and their properties,
 * and allowing them to activate and deactivate workspaces.
 *
 * After a client binds the zext_workspace_manager_v1, each workspace will be
 * sent via the workspace event.
 */
extern const struct wl_interface zext_workspace_manager_v1_interface;
#endif
#ifndef ZEXT_WORKSPACE_GROUP_HANDLE_V1_INTERFACE
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_INTERFACE
/**
 * @page page_iface_zext_workspace_group_handle_v1 zext_workspace_group_handle_v1
 * @section page_iface_zext_workspace_group_handle_v1_desc Description
 *
 * A zext_workspace_group_handle_v1 object represents a a workspace group
 * that is assigned a set of outputs and contains a number of workspaces.
 *
 * The set of outputs assigned to the workspace group is conveyed to the client via
 * output_enter and output_leave events, and its workspaces are conveyed with
 * workspace events.
 *
 * For example, a compositor which has a set of workspaces for each output may
 * advertise a workspace group (and its workspaces) per output, whereas a compositor
 * where a workspace spans all outputs may advertise a single workspace group for all
 * outputs.
 * @section page_iface_zext_workspace_group_handle_v1_api API
 * See @ref iface_zext_workspace_group_handle_v1.
 */
/**
 * @defgroup iface_zext_workspace_group_handle_v1 The zext_workspace_group_handle_v1 interface
 *
 * A zext_workspace_group_handle_v1 object represents a a workspace group
 * that is assigned a set of outputs and contains a number of workspaces.
 *
 * The set of outputs assigned to the workspace group is conveyed to the client via
 * output_enter and output_leave events, and its workspaces are conveyed with
 * workspace events.
 *
 * For example, a compositor which has a set of workspaces for each output may
 * advertise a workspace group (and its workspaces) per output, whereas a compositor
 * where a workspace spans all outputs may advertise a single workspace group for all
 * outputs.
 */
extern const struct wl_interface zext_workspace_group_handle_v1_interface;
#endif
#ifndef ZEXT_WORKSPACE_HANDLE_V1_INTERFACE
#define ZEXT_WORKSPACE_HANDLE_V1_INTERFACE
/**
 * @page page_iface_zext_workspace_handle_v1 zext_workspace_handle_v1
 * @section page_iface_zext_workspace_handle_v1_desc Description
 *
 * A zext_workspace_handle_v1 object represents a a workspace that handles a
 * group of surfaces.
 *
 * Each workspace has a name, conveyed to the client with the name event; a
 * list of states, conveyed to the client with the state event; and
 * optionally a set of coordinates, conveyed to the client with the
 * coordinates event. The client may request that the compositor activate or
 * deactivate the workspace.
 *
 * Each workspace can belong to only a single workspace group.
 * Depepending on the compositor policy, there might be workspaces with
 * the same name in different workspace groups, but these workspaces are still
 * separate (e.g. one of them might be active while the other is not).
 * @section page_iface_zext_workspace_handle_v1_api API
 * See @ref iface_zext_workspace_handle_v1.
 */
/**
 * @defgroup iface_zext_workspace_handle_v1 The zext_workspace_handle_v1 interface
 *
 * A zext_workspace_handle_v1 object represents a a workspace that handles a
 * group of surfaces.
 *
 * Each workspace has a name, conveyed to the client with the name event; a
 * list of states, conveyed to the client with the state event; and
 * optionally a set of coordinates, conveyed to the client with the
 * coordinates event. The client may request that the compositor activate or
 * deactivate the workspace.
 *
 * Each workspace can belong to only a single workspace group.
 * Depepending on the compositor policy, there might be workspaces with
 * the same name in different workspace groups, but these workspaces are still
 * separate (e.g. one of them might be active while the other is not).
 */
extern const struct wl_interface zext_workspace_handle_v1_interface;
#endif

/**
 * @ingroup iface_zext_workspace_manager_v1
 * @struct zext_workspace_manager_v1_interface
 */
struct zext_workspace_manager_v1_interface {
	/**
	 * all requests about the workspaces have been sent
	 *
	 * The client must send this request after it has finished
	 * sending other requests. The compositor must process a series of
	 * requests preceding a commit request atomically.
	 *
	 * This allows changes to the workspace properties to be seen as
	 * atomic, even if they happen via multiple events, and even if
	 * they involve multiple zext_workspace_handle_v1 objects, for
	 * example, deactivating one workspace and activating another.
	 */
	void (*commit)(struct wl_client *client,
		       struct wl_resource *resource);
	/**
	 * stop sending events
	 *
	 * Indicates the client no longer wishes to receive events for
	 * new workspace groups. However the compositor may emit further
	 * workspace events, until the finished event is emitted.
	 *
	 * The client must not send any more requests after this one.
	 */
	void (*stop)(struct wl_client *client,
		     struct wl_resource *resource);
};

#define ZEXT_WORKSPACE_MANAGER_V1_WORKSPACE_GROUP 0
#define ZEXT_WORKSPACE_MANAGER_V1_DONE 1
#define ZEXT_WORKSPACE_MANAGER_V1_FINISHED 2

/**
 * @ingroup iface_zext_workspace_manager_v1
 */
#define ZEXT_WORKSPACE_MANAGER_V1_WORKSPACE_GROUP_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_manager_v1
 */
#define ZEXT_WORKSPACE_MANAGER_V1_DONE_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_manager_v1
 */
#define ZEXT_WORKSPACE_MANAGER_V1_FINISHED_SINCE_VERSION 1

/**
 * @ingroup iface_zext_workspace_manager_v1
 */
#define ZEXT_WORKSPACE_MANAGER_V1_COMMIT_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_manager_v1
 */
#define ZEXT_WORKSPACE_MANAGER_V1_STOP_SINCE_VERSION 1

/**
 * @ingroup iface_zext_workspace_manager_v1
 * Sends an workspace_group event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_manager_v1_send_workspace_group(struct wl_resource *resource_, struct wl_resource *workspace_group)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_MANAGER_V1_WORKSPACE_GROUP, workspace_group);
}

/**
 * @ingroup iface_zext_workspace_manager_v1
 * Sends an done event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_manager_v1_send_done(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_MANAGER_V1_DONE);
}

/**
 * @ingroup iface_zext_workspace_manager_v1
 * Sends an finished event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_manager_v1_send_finished(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_MANAGER_V1_FINISHED);
}

/**
 * @ingroup iface_zext_workspace_group_handle_v1
 * @struct zext_workspace_group_handle_v1_interface
 */
struct zext_workspace_group_handle_v1_interface {
	/**
	 * create a new workspace
	 *
	 * Request that the compositor create a new workspace with the
	 * given name.
	 *
	 * There is no guarantee that the compositor will create a new
	 * workspace, or that the created workspace will have the provided
	 * name.
	 */
	void (*create_workspace)(struct wl_client *client,
				 struct wl_resource *resource,
				 const char *workspace);
	/**
	 * destroy the zext_workspace_handle_v1 object
	 *
	 * Destroys the zext_workspace_handle_v1 object.
	 *
	 * This request should be called either when the client does not
	 * want to use the workspace object any more or after the remove
	 * event to finalize the destruction of the object.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
};

#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_OUTPUT_ENTER 0
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_OUTPUT_LEAVE 1
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_WORKSPACE 2
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_REMOVE 3

/**
 * @ingroup iface_zext_workspace_group_handle_v1
 */
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_OUTPUT_ENTER_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_group_handle_v1
 */
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_OUTPUT_LEAVE_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_group_handle_v1
 */
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_WORKSPACE_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_group_handle_v1
 */
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_REMOVE_SINCE_VERSION 1

/**
 * @ingroup iface_zext_workspace_group_handle_v1
 */
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_CREATE_WORKSPACE_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_group_handle_v1
 */
#define ZEXT_WORKSPACE_GROUP_HANDLE_V1_DESTROY_SINCE_VERSION 1

/**
 * @ingroup iface_zext_workspace_group_handle_v1
 * Sends an output_enter event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_group_handle_v1_send_output_enter(struct wl_resource *resource_, struct wl_resource *output)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_GROUP_HANDLE_V1_OUTPUT_ENTER, output);
}

/**
 * @ingroup iface_zext_workspace_group_handle_v1
 * Sends an output_leave event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_group_handle_v1_send_output_leave(struct wl_resource *resource_, struct wl_resource *output)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_GROUP_HANDLE_V1_OUTPUT_LEAVE, output);
}

/**
 * @ingroup iface_zext_workspace_group_handle_v1
 * Sends an workspace event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_group_handle_v1_send_workspace(struct wl_resource *resource_, struct wl_resource *workspace)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_GROUP_HANDLE_V1_WORKSPACE, workspace);
}

/**
 * @ingroup iface_zext_workspace_group_handle_v1
 * Sends an remove event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_group_handle_v1_send_remove(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_GROUP_HANDLE_V1_REMOVE);
}

#ifndef ZEXT_WORKSPACE_HANDLE_V1_STATE_ENUM
#define ZEXT_WORKSPACE_HANDLE_V1_STATE_ENUM
/**
 * @ingroup iface_zext_workspace_handle_v1
 * types of states on the workspace
 *
 * The different states that a workspace can have.
 */
enum zext_workspace_handle_v1_state {
	/**
	 * the workspace is active
	 */
	ZEXT_WORKSPACE_HANDLE_V1_STATE_ACTIVE = 0,
	/**
	 * the workspace requests attention
	 */
	ZEXT_WORKSPACE_HANDLE_V1_STATE_URGENT = 1,
	/**
	 * the workspace is not visible
	 *
	 * The workspace is not visible in its workspace group, and
	 * clients attempting to visualize the compositor workspace state
	 * should not display such workspaces.
	 */
	ZEXT_WORKSPACE_HANDLE_V1_STATE_HIDDEN = 2,
};
#endif /* ZEXT_WORKSPACE_HANDLE_V1_STATE_ENUM */

/**
 * @ingroup iface_zext_workspace_handle_v1
 * @struct zext_workspace_handle_v1_interface
 */
struct zext_workspace_handle_v1_interface {
	/**
	 * destroy the zext_workspace_handle_v1 object
	 *
	 * Destroys the zext_workspace_handle_v1 object.
	 *
	 * This request should be called either when the client does not
	 * want to use the workspace object any more or after the remove
	 * event to finalize the destruction of the object.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * activate the workspace
	 *
	 * Request that this workspace be activated.
	 *
	 * There is no guarantee the workspace will be actually activated,
	 * and behaviour may be compositor-dependent. For example,
	 * activating a workspace may or may not deactivate all other
	 * workspaces in the same group.
	 */
	void (*activate)(struct wl_client *client,
			 struct wl_resource *resource);
	/**
	 * activate the workspace
	 *
	 * Request that this workspace be deactivated.
	 *
	 * There is no guarantee the workspace will be actually
	 * deactivated.
	 */
	void (*deactivate)(struct wl_client *client,
			   struct wl_resource *resource);
	/**
	 * remove the workspace
	 *
	 * Request that this workspace be removed.
	 *
	 * There is no guarantee the workspace will be actually removed.
	 */
	void (*remove)(struct wl_client *client,
		       struct wl_resource *resource);
};

#define ZEXT_WORKSPACE_HANDLE_V1_NAME 0
#define ZEXT_WORKSPACE_HANDLE_V1_COORDINATES 1
#define ZEXT_WORKSPACE_HANDLE_V1_STATE 2
#define ZEXT_WORKSPACE_HANDLE_V1_REMOVE 3

/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_NAME_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_COORDINATES_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_STATE_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_REMOVE_SINCE_VERSION 1

/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_ACTIVATE_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_DEACTIVATE_SINCE_VERSION 1
/**
 * @ingroup iface_zext_workspace_handle_v1
 */
#define ZEXT_WORKSPACE_HANDLE_V1_REMOVE_SINCE_VERSION 1

/**
 * @ingroup iface_zext_workspace_handle_v1
 * Sends an name event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_handle_v1_send_name(struct wl_resource *resource_, const char *name)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_HANDLE_V1_NAME, name);
}

/**
 * @ingroup iface_zext_workspace_handle_v1
 * Sends an coordinates event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_handle_v1_send_coordinates(struct wl_resource *resource_, struct wl_array *coordinates)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_HANDLE_V1_COORDINATES, coordinates);
}

/**
 * @ingroup iface_zext_workspace_handle_v1
 * Sends an state event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_handle_v1_send_state(struct wl_resource *resource_, struct wl_array *state)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_HANDLE_V1_STATE, state);
}

/**
 * @ingroup iface_zext_workspace_handle_v1
 * Sends an remove event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zext_workspace_handle_v1_send_remove(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZEXT_WORKSPACE_HANDLE_V1_REMOVE);
}

#ifdef  __cplusplus
}
#endif

#endif
