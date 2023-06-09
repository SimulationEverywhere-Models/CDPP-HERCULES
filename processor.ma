[top]
components : data_queue@Queue
components : comparitor@Comparitor 
components : recorder@Recorder
 
out : out
in : data_in
in : WOW_in

Link : data_in new_data@comparitor
Link : WOW_in start_stop@comparitor

Link : data_out@comparitor in@data_queue
Link : out@data_queue in@recorder

Link : data_out@recorder done@data_queue
Link : data_out@recorder out

[comparitor]
preparation : 00:00:00:200 

[data_queue]
preparation : 00:00:00:500

[recorder]
preparation : 00:00:00:500
