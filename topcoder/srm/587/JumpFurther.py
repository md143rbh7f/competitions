class JumpFurther(object):
    def furthest(self, n, x):
        h = 0
        for i in range(n):
            h += i + 1
            if h == x:
                h -= 1
        return h
