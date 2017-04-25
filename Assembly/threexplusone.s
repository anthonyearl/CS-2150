	;; Brandon Feng yf2km threexplusone.s 5PM
	;; Optimizations: use bitshift (shr) instead of idiv, minimize registers used, and minimize loops and if/else statments
	global threexplusone
	section .text

threexplusone:
	xor	rax, rax
	cmp	rdi, 1
	je	end
	jmp	recurse

recurse:	
	mov	r10, rdi
	shr	r10, 1
	jc	odd
	shr	rdi, 1
	call	threexplusone
	inc	rax
	jmp	end

odd:
	imul	rdi, 3
	add	rdi, 1
	call	threexplusone
	inc	rax
	jmp	end

end:
	ret
