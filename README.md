# DTMF_Decoder
MT8870 DTMF decoder for POTS phone line interfacing <BR>
![pcb](Assembled_PCB.png)<br>
This pcb allows connecting across a phone line tip and ring and when DTMF signals are present, they are decoded into 4 bit data with a data ready signal.<br>
An Arduino can then detect DTMF touch tones present on a phone line.<br>
Note: It is recommended to only connect this circuit to a phone line after it is taken off hook to keep the AC voltages low, such as audio signals and not a high voltage ring signal.<br>
This can be achieved by switching the circuit into the phone line with a relay.<br><br>
This circuit has only been tested on a simulated phone line in a workshop environment and is not guaranteed to meet official telephone line specifications.
