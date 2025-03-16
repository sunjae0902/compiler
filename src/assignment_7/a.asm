	      INT   0, 80
	      SUP   0, main
	      RET   0, 0
gcd:
	      INT   0, 20
L2:
	      LOD   1, 12
	      LOD   1, 16
	     NEQI   0, 0
	      JPC   0, L3
	      LOD   1, 12
	      LOD   1, 16
	     LSSI   0, 0
	      JPC   0, L4
	      LDA   1, 16
	      LOD   1, 16
	      LOD   1, 12
	     SUBI   0, 0
	      STX   0, 1
	      POP   0, 1
	      JMP   0, L5
L4:
	      LDA   1, 12
	      LOD   1, 12
	      LOD   1, 16
	     SUBI   0, 0
	      STX   0, 1
	      POP   0, 1
L5:
L1:
	      JMP   0, L2
L3:
	      LDA   1, -4
	      LOD   1, 12
	      STO   0, 1
	      RET   0, 0
	      RET   0, 0
main:
	      INT   0, 20
	      INT   0, 12
	      LDA   0, 12
	      POP   0, 4
	     ADDR   0, printf
	      CAL   0, 0
	      INT   0, 12
	      LDA   0, 36
	      LDA   1, 12
	      LDA   1, 16
	      POP   0, 6
	     ADDR   0, scanf
	      CAL   0, 0
	      INT   0, 12
	      LDA   0, 44
	      LOD   1, 12
	      LOD   1, 16
	      INT   0, 16
	      LOD   1, 12
	      LOD   1, 16
	      POP   0, 5
	     ADDR   0, gcd
	      CAL   0, 0
	      POP   0, 7
	     ADDR   0, printf
	      CAL   0, 0
	      INT   0, 12
	      LDA   0, 72
	      POP   0, 4
	     ADDR   0, printf
	      CAL   0, 0
	      LDA   1, -4
	     LITI   0, 0
	      STO   0, 1
	      RET   0, 0
	      RET   0, 0
.literal    12 "Enter two integers: "
.literal    36 "%d %d"
.literal    44 "gcd of %d and %d is %d\n"
