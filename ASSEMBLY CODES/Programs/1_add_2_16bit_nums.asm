	MVI A, CDH ;move CD value to A
    ADI 43H ;Add 34 with value in A(i.e with CD)
    MOV D, A ;move result stored in A to Register D
    ;Addition of higher bit value(hsb)
    MVI A, ABH 
    ACI 65H ;ADD WITH CARRY IMMEDIATELY
    MOV C, A 
    MVI A, 00H ;TO GEL LEFT CARRY ADDING WITH 00H
    ADC A
    MOV B, A
    HLT