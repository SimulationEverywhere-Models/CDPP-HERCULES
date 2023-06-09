[top]
components : WOW_generator@Generator
components : flight_data_generator@Flight_Data_Generator
components : processor
 
out : out

Link : out@WOW_generator on_off@processor
Link : out@flight_data_generator data_in@processor
Link : out@processor out

[processor]
components : data_queue@Queue
components : comparitor@Comparitor 
components : recorder@Recorder 

out : out
in : data_in
in : on_off

Link : data_in new_data@comparitor
Link : on_off start_stop@comparitor
Link : data_out@comparitor in@data_queue


Link : out@data_queue in@recorder
Link : data_out@recorder done@data_queue
Link : data_out@recorder out

[comparitor]
preparation : 00:00:00:200

[data_queue]
preparation : 00:00:00:500

[recorder]
preparation : 00:00:00:250

[flight_data_generator]
preparation : 00:00:00:250 

[WOW_generator]
distribution : normal
mean : 3600000
deviation : 600000

