/*
    COPYRIGHT NOTICE

    This program is the proprietary property of IXI Ltd, a subsidiary
    of the Santa Cruz Operation (SCO). Use, reproduction, production
    of amended versions and/or transfer of this program is permitted
    PROVIDED THAT:

    (a)  This legend be preserved on any such reproduction and amended
         version.

    (b)  Any recipient of such reproduction or amended version accept
         the conditions set out in this legend.

    IXI accepts no liability whatsoever in relation to any use to
    which this program may be put and gives no warranty as to the
    program's suitability for any purpose.

    All rights reserved.

    Copyright (c) 1995, 1996

*/


/* SCO CID (IXI) CascadeBP.h,v 1.1 1996/08/08 14:12:20 wendland Exp */

%%
#ifndef __MOTIF_P_HEADERS
#error Unexpected access to Motif P headers
#endif
%%

+USE "motif/1_2", "Xm/CascadeB.h";
+USE "motif/1_2", "Xm/LabelP.h";

+FIELD (struct) _XmCascadeButtonPart := { 

	XtCallbackList	activate_callback;
	XtCallbackList	cascade_callback;
	
	Widget		submenu;
	Pixmap		cascade_pixmap; 
    	int		map_delay; 

	Boolean		armed;
	XRectangle	cascade_rect;
	XtIntervalId	timer;
	Pixmap		armed_pixmap;

};

+TYPEDEF _XmCascadeButtonPart XmCascadeButtonPart;

+FIELD (struct) _XmCascadeButtonRec := { 

	CorePart		core;
	XmPrimitivePart		primitive;
	XmLabelPart		label;
	XmCascadeButtonPart	cascade_button;
};

+TYPEDEF _XmCascadeButtonRec XmCascadeButtonRec;

/* 
  this (and the following typedef) are obsolete and kept for compatibility only 
*/

+FIELD (struct) _XmCascadeButtonWidgetRec := {

	CorePart		core;
	XmPrimitivePart		primitive;
	XmLabelPart		label;
	XmCascadeButtonPart	cascade_button;
};

+TYPEDEF _XmCascadeButtonWidgetRec XmCascadeButtonWidgetRec;

+FIELD (struct) XmCascadeButtonClassPart := { 

	XtPointer		extension;
};


+FIELD (struct) XmCascadeButtonClassRec := { 

	CoreClassPart			core_class;
	XmPrimitiveClassPart		primitive_class;
	XmLabelClassPart		label_class;
	XmCascadeButtonClassPart	cascade_button_class;
};

+EXP lvalue XmCascadeButtonClassRec xmCascadeButtonClassRec;

+MACRO Widget CB_Submenu(Widget);
+MACRO XtCallbackList CB_ActivateCall(Widget);
+MACRO XtCallbackList CB_CascadeCall(Widget);
+MACRO Pixmap CB_CascadePixmap(Widget);
+MACRO Pixmap CB_ArmedPixmap(Widget);
+MACRO Position CB_Cascade_x(Widget);
+MACRO Position CB_Cascade_y(Widget);
+MACRO Dimension CB_Cascade_width(Widget);
+MACRO Dimension CB_Cascade_height(Widget);
+MACRO Boolean CB_HasCascade(Widget);

+CONST int XmCB_ARMED_BIT;
+CONST int XmCB_TRAVERSE_BIT;

+MACRO int CB_IsArmed(Widget);
+MACRO int CB_Traversing(Widget);

+DEFINE CB_SetBit(byte,bit,v) %% byte = (byte & (~bit)) | (v ? bit : 0) %%;

+MACRO void CB_SetArmed(Widget, Boolean);
+MACRO void CB_SetTraverse(Widget, Boolean);

+FUNC void _XmCBHelp(Widget, XEvent *, String *, Cardinal *);
+FUNC void _XmCascadingPopup(Widget, XEvent *, int);



