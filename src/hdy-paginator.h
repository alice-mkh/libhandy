/*
 * Copyright (C) 2019 Alexander Mikhaylenko <exalm7659@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#if !defined(_HANDY_INSIDE) && !defined(HANDY_COMPILATION)
#error "Only <handy.h> can be included directly."
#endif

#include <gtk/gtk.h>
#include "hdy-enums.h"

G_BEGIN_DECLS

#define HDY_TYPE_PAGINATOR (hdy_paginator_get_type())

G_DECLARE_FINAL_TYPE (HdyPaginator, hdy_paginator, HDY, PAGINATOR, GtkEventBox)

typedef enum {
  HDY_PAGINATOR_INDICATOR_STYLE_NONE,
  HDY_PAGINATOR_INDICATOR_STYLE_LINES,
  HDY_PAGINATOR_INDICATOR_STYLE_DOTS,
} HdyPaginatorIndicatorStyle;

HdyPaginator *hdy_paginator_new (void);

void          hdy_paginator_prepend (HdyPaginator *self,
                                     GtkWidget    *child);
void          hdy_paginator_insert (HdyPaginator *self,
                                    GtkWidget    *child,
                                    int           position);
void          hdy_paginator_reorder (HdyPaginator *self,
                                     GtkWidget    *child,
                                     int           position);

void          hdy_paginator_scroll_to (HdyPaginator *self,
                                       GtkWidget    *widget);
void          hdy_paginator_scroll_to_full (HdyPaginator *self,
                                            GtkWidget    *widget,
                                            int64_t       duration);

int           hdy_paginator_get_n_pages (HdyPaginator *self);
double        hdy_paginator_get_position (HdyPaginator *self);

gboolean      hdy_paginator_get_interactive (HdyPaginator *self);
void          hdy_paginator_set_interactive (HdyPaginator *self,
                                             gboolean      interactive);

HdyPaginatorIndicatorStyle hdy_paginator_get_indicator_style (HdyPaginator *self);
void          hdy_paginator_set_indicator_style (HdyPaginator               *self,
                                                 HdyPaginatorIndicatorStyle  style);

gboolean      hdy_paginator_get_center_content (HdyPaginator *self);
void          hdy_paginator_set_center_content (HdyPaginator *self,
                                                gboolean      center_content);

int           hdy_paginator_get_spacing (HdyPaginator *self);
void          hdy_paginator_set_spacing (HdyPaginator *self,
                                         int           spacing);

uint          hdy_paginator_get_animation_duration (HdyPaginator *self);
void          hdy_paginator_set_animation_duration (HdyPaginator *self,
                                                    uint          duration);

G_END_DECLS
