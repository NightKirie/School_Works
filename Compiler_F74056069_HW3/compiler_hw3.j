.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1
	istore 0
	iload 0
	iconst_1
	iadd
	istore 0
	iload 0
	iconst_1
	iadd
	istore 0
	ldc 1
	ldc 1
	iadd
	istore 1
WHILE_BEGIN_0:
	iload 0
	ldc 6
	isub
	iflt WHILE_TRUE_0
	goto WHILE_FALSE_0
WHILE_TRUE_0:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	iload 0
	iconst_1
	iadd
	istore 0
	goto WHILE_BEGIN_0
WHILE_FALSE_0:
	goto WHILE_EXIT_0
WHILE_EXIT_0:
	iload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
