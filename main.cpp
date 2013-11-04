//
//  main.cpp
//  Lab0
//
//  Created by Fredrik Lind on 2013-11-04.
//  Copyright (c) 2013 Fredrik Lind. All rights reserved.
//

#include <gst/gst.h>

int main(int argc, char *argv[]) {
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;
    
    /* Initialize GStreamer */
    gst_init (&argc, &argv);
    
    /* Build the pipeline */
    pipeline = gst_parse_launch ("playbin2 uri=http://video.webmfiles.org/big-buck-bunny_trailer.webm", 0);
    
    /* Start playing */
    gst_element_set_state (pipeline, GST_STATE_PLAYING);
    
    /* Wait until error or EOS */
    bus = gst_element_get_bus (pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS);
    
    /* Free resources */
    if (msg != NULL)
        gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    return 0;

// Insert Joke Here //
}
