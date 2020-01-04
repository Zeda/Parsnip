;===============================================================
; TI-OS Equates
;===============================================================
#define db .db
#define bcall(x) rst 28h \ .dw x
#define rMov9ToOP1 20h
#define rFindSym 10h
_FindAlphaDn    = 4A47h
_FindAlphaUp    = 4A44h
_RclAns         = 4AD7h
_ChkFindSym     = 42F1h
_DispHL         = 4507h
_CreateTempStr  = 4324h
_SetParserHook  = 5026h
_CreateVar      = 4E70h
_CreateAppVar   = 4E6Ah
_CreatePict     = 4333h
_EnoughMem      = 42FDh
_InsertMem      = 42F7h
_Get_Tok_Strng  = 4594h
_DelMem         = 4357h
_JForceCmdNoChar= 4027h
_JError         = 44D7h
_DelVarArc      = 4FC6h
_CreateStrng    = 4327h
_CreateReal     = 430Fh
_SetXXXXOP2     = 4792h
_Arc_Unarc      = 4FD8h
_ConvKeyToTok   = 4A02h
_GetKeyRetOff   = 500Bh
_RunIndicOff    = 4570h
_DeleteTempPrograms = 5041h
_MemChk         = 42E5h
_clrTxtShd      = 454Ch
_saveCmdShadow  = 4573h
_PutS           = 450Ah
_PutC           = 4504h
_OP5ToOP1       = 413Bh
_OP1ToOP5       = 4153h
_NewLine        = 452Eh
_HomeUp         = 4558h
_ClrScrnFull    = 4546h
appErr1         = 984Dh
appErr2         = 985Ah
cxErrorEP       = 8595h
curRow          = 844Bh
curCol          = 844Ch
kbdScanCode     = 843Fh
basic_prog      = 9652h
progStart       = 965Bh
parsePtr        = 965Dh
progEnd         = 965Fh
parserHookPtr   = 9BACh
OP1             = 8478h
OP2             = 8483h
OP3             = 848Eh
OP4             = 8499h
OP5             = 84A4h
OP6             = 84AFh  ;11 bytes
flags           = 89F0h
saveSScreen     = 86ECh
textShadow      = 8508h
plotSScreen     = 9340h
appBackUpScreen = 9872h
progPtr         = 9830h
FPS             = 9824h
OPS             = 9828h
iMathPtr1       = 84D3h  ;10 bytes
iMathPtr2       = 84D5h
iMathPtr3       = 84D7h
iMathPtr4       = 84D9h
iMathPtr5       = 84DBh
smallEditRAM    = 90D3h  ;108 bytes
cmdShadow       = 966Eh  ;128 bytes
pTemp           = 982Eh ;bottom of named vars VAT
tempSwapArea    = 82A5h
ramCode         = 8100h
fmtDigits = 97B0h

;===============================================================
; TI-OS Flags
;===============================================================
CursorFlags     = 12
CursorActive    =   3

onFlags         = 9        ;on key flags
onInterrupt     =   4      ;1=on key interrupt request

curFlags        = 12       ;Cursor
fmtEdit         =   0      ;1=format number for editing
curAble         =   2      ;1=cursor flash is enabled
curOn           =   3      ;1=cursor is showing
curLock         =   4      ;1=cursor is locked off
cmdVirgin       =   5      ;1=nothing has been typed in cmd bfr
;----------------------------------------------------------------------
indicFlags        = 18         ;Indicator flags
indicRun          =   0        ;1=run indicator ON
shiftFlags        = 18         ;[2nd] and [ALPHA] flags
shift2nd          =   3        ;1=[2nd] has been pressed
shiftAlpha        =   4        ;1=[ALPHA] has been pressed
shiftLwrAlph      =   5        ;1=lower case, 0=upper case
shiftALock        =   6        ;1=alpha lock has been pressed
shiftKeepAlph     =   7        ;1=cannot cancel alpha shift


;===============================================================
; Parsnip Equates
;===============================================================
;

#define K_DELAY_DEFAULT 13
#define K_DELAY_ACCEL 3
#define char_TI_TOK
#define EXTERNAL_FORMAT_LEN    ;Uses an external reference to get the format length
#define EXTERNAL_FORMAT_LEN_LOC fmtDigits    ;Use for TI-OS


; Used by the VAT sort routine
VATPtr      = iMathPtr1
VATPtr_next = iMathPtr2

pvars       = smallEditRAM
gbuf        = plotSScreen
TSA         = tempSwapArea

type_param_end= 0
type_ui8      = 1
type_ui16     = 2
type_ui32     = 3
type_fixed88  = 4
type_fixed1616= 5
type_var      = 6
type_true     = 7
type_false    = 8
type_tstr_ref = 9
type_raw      = 10
type_str      = 11
type_str_ref  = 12
type_single   = 13
type_xfloat   = 14
type_list     = 15
type_list_ref = 16
type_char     = 17
type_ref      = 18


X_CONST_0     = 6
X_CONST_1     = 7
X_CONST_PI    = 0
X_CONST_e     = 1

tok_internal  = $F1
tok_index     = $FF

;===============================================================
; Variables (RAM usage)
;===============================================================
;
; stored in OP6
temp_word_1 = OP6           ;2
temp_word_2 = temp_word_1+2 ;2
temp_word_3 = temp_word_2+2 ;2
temp_word_4 = temp_word_3+2 ;2
temp_word_5 = temp_word_4+2 ;2
text_mode   = temp_word_5+2 ;1 ;only lower 2 bits used currently

; stored in appErr2
text_delay  = appErr2       ;1
text_logic  = text_delay+1  ;1
text_row    = text_logic+1  ;1 \
text_col    = text_row+1    ;1 /
sp_save     = text_col+1    ;2
Ans         = sp_save+2     ;2
font_ptr    = Ans+2         ;2
k_save      = font_ptr+2    ;1 \
k_count     = k_save+1      ;1 |
k_delay     = k_count+1     ;1 /

gray_mask   = 80C0h         ;1 \    ;xfloat routines need up to 187 bytes.
gray_method = gray_mask+1   ;1 /
gbuf_temp   = gray_method+1 ;2
graybuf_ptr = gbuf_temp+2   ;2
buf_ptr     = graybuf_ptr+2 ;2

;This equate is for used by vars that are from distinct context.
;For example, parser vars are not used in the main menu, and vice-versa,
;so they can be safely mapped to the same address.
disjoint_context = buf_ptr+2

;---------
operandstack_ptr    = disjoint_context
operandstack_bottom = operandstack_ptr+2
operandstack_top    = operandstack_bottom+2
opstack_ptr         = operandstack_top+2
heap_ptr            = opstack_ptr+2
heap_bottom         = heap_ptr+2
heap_top            = heap_bottom+2
var_names_base      = heap_top+2
var_names_ptr       = var_names_base+2
var_names_top       = var_names_ptr+2
vars_count          = var_names_top+2
temp_var_count      = var_count+2       ;1 byte


;---------
;Menu
main_menu_cursor    = disjoint_context
main_menu_cursor_max= main_menu_cursor+1
main_menu_index     = main_menu_cursor_max+1
;---------

;==============================
;Flags
;==============================
InternalFlag    = 33
SlowTextFlag    =   0
IntActiveFlag   =   1
FactorialFlag   =   2
errorChecking   =   3
grayFlag        =   4   ;this determines the checker pattern for the next gray object drawn
bit32           =   5   ;This determines if the output was 32-bit or not
Mod2nd          =   6
grayMode        =   7   ;This determines the checker pattern for grayscale mode

MainMenuFlags   = 34
grammer_only    =   0
appv_only       =   1
asm_only        =   2

UserFlags       = 34
InvertTextFlag  =   0
InvertLCDFlag   =   1
OnBlockFlag     =   2

UserFlags2      = 35
