class AlbertoTheAviator(object):
    def MaximumFlights(self, start, dur, ref):
        fs = sorted(zip(ref, dur), reverse=True)
        best = [0] * (start + 1)
        for ref, dur in fs:
            for f in range(dur, start + 1):
                best[f - dur + ref] = max(best[f - dur + ref], best[f] + 1)
        return max(best)
