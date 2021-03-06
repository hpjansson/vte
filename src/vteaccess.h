/*
 * Copyright (C) 2002 Red Hat, Inc.
 *
 * This is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef vte_vteaccess_h_included
#define vte_vteaccess_h_included

#ident "$Id$"

#include <glib.h>
#include <gtk/gtk.h>
#include "vte.h"

G_BEGIN_DECLS

/* The terminal accessibility object itself. */
typedef struct _VteTerminalAccessible VteTerminalAccessible;
struct _VteTerminalAccessible {
	/*< public > */
	GtkAccessible parent;
	/*< private > */
	/* Unknown GailWidget implementation stuffs, exact size of which is
	 * worked out at run-time. */
};

/* The object's class structure. */
typedef struct _VteTerminalAccessibleClass VteTerminalAccessibleClass;
struct _VteTerminalAccessibleClass {
	/*< public > */
	/* Inherited parent class. */
	GtkAccessibleClass parent_class;
	/*< private > */
	/* Unknown GailWidgetClass implementation stuffs, exact size of which
	 * is worked out at run-time. */
};

/* The object's type. */
GtkType vte_terminal_accessible_get_type(void);

#define VTE_TYPE_TERMINAL_ACCESSIBLE	(vte_terminal_accessible_get_type())
#define VTE_TERMINAL_ACCESSIBLE(obj)	(GTK_CHECK_CAST((obj),\
							VTE_TYPE_TERMINAL_ACCESSIBLE,\
							VteTerminalAccessible))
#define VTE_TERMINAL_ACCESSIBLE_CLASS(klass)	GTK_CHECK_CLASS_CAST((klass),\
								     VTE_TYPE_TERMINAL_ACCESSIBLE,\
								     VteTerminalAccessibleClass)
#define VTE_IS_TERMINAL_ACCESSIBLE(obj)		GTK_CHECK_TYPE((obj),\
							       VTE_TYPE_TERMINAL_ACCESSIBLE)
#define VTE_IS_TERMINAL_ACCESSIBLE_CLASS(klass)	GTK_CHECK_CLASS_TYPE((klass),\
								     VTE_TYPE_TERMINAL_ACCESSIBLE)
#define VTE_TERMINAL_ACCESSIBLE_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), VTE_TYPE_TERMINAL_ACCESSIBLE, VteTerminalAccessibleClass))

AtkObject *vte_terminal_accessible_new(VteTerminal *terminal);

/* The terminal accessibility object's factory. */
typedef struct _VteTerminalAccessibleFactory VteTerminalAccessibleFactory;
struct _VteTerminalAccessibleFactory {
	/*< public > */
	AtkObjectFactory parent;
	/*< private > */
};

/* The object's class structure. */
typedef struct _VteTerminalAccessibleFactoryClass VteTerminalAccessibleFactoryClass;
struct _VteTerminalAccessibleFactoryClass {
	/*< public > */
	AtkObjectFactoryClass parent;
	/*< private > */
};

/* The object's factory's type. */
GtkType vte_terminal_accessible_factory_get_type(void);

#define VTE_TYPE_TERMINAL_ACCESSIBLE_FACTORY	(vte_terminal_accessible_factory_get_type())
#define VTE_TERMINAL_ACCESSIBLE_FACTORY(obj)	(GTK_CHECK_CAST((obj),\
								VTE_TYPE_TERMINAL_ACCESSIBLE_FACTORY,\
								VteTerminalAccessibleFactory))
#define VTE_TERMINAL_ACCESSIBLE_FACTORY_CLASS(klass)	GTK_CHECK_CLASS_CAST((klass),\
									     VTE_TYPE_TERMINAL_ACCESSIBLE_FACTORY,\
									     VteTerminalAccessibleFactoryClass)
#define VTE_IS_TERMINAL_ACCESSIBLE_FACTORY(obj)		GTK_CHECK_TYPE((obj),\
								       VTE_TYPE_TERMINAL_ACCESSIBLE_FACTORY)
#define VTE_IS_TERMINAL_ACCESSIBLE_FACTORY_CLASS(klass)	GTK_CHECK_CLASS_TYPE((klass),\
									     VTE_TYPE_TERMINAL_ACCESSIBLE_FACTORY)
#define VTE_TERMINAL_ACCESSIBLE_FACTORY_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), VTE_TYPE_TERMINAL_ACCESSIBLE_FACTORY, VteTerminalAccessibleFactoryClass))

AtkObjectFactory *vte_terminal_accessible_factory_new(void);

G_END_DECLS

#endif
