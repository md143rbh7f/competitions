class WaterAndOxygen(object):
    def maxDays(self, rh, ro, ch, co):
	if rh * co > ch * ro:
            c = float(rh * co - ch * ro) / (ch * 0.5 + co)
            rh -= c
            ro += c * 0.5
	return min(float(rh) / ch, float(ro) / co)
