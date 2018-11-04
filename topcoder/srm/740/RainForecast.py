class RainForecast(object):
    def predictRain(_, p, qs):
	p *= 0.01
	for q in qs:
            p += 0.01 * q * (1 - 2 * p)
	return max(p, 1 - p);
