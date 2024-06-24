LokGasMineScreenPlay = ScreenPlay:new {
	numberOfActs = 1,
	screenplayName = "LokGasMineScreenPlay",

	ScreenPSpawns = {
		{"lok", "enraged_miner_caveLokGasMine", 300, -12.252, -40.579, -73.706, 73.896, 5645587},
		{"lok", "enraged_miner_caveLokGasMine", 300, -6.352, -40.298, -79.144, 52.180, 5645587},
		{"lok", "enraged_miner_caveLokGasMine", 300, 12.943, -40.305, -76.478, 35.686, 5645587},
		{"lok", "enraged_miner_caveLokGasMine", 300, 46.575, -46.805, -51.172, -155.958, 5645588},
		{"lok", "enraged_miner_caveLokGasMine", 300, 50.996, -46.168, -62.670, 141.897, 5645588},
		{"lok", "enraged_miner_caveLokGasMine", 300, 40.884, -46.735, -80.065, 6.201, 5645588},
		{"lok", "enraged_miner_caveLokGasMine", 300, 25.237, -45.685, -107.802, 22.793, 5645588},
		{"lok", "enraged_miner_caveLokGasMine", 300, -0.098, -45.474, -145.263, 54.306, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, -6.762, -45.537, -145.634, 51.927, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, -10.649, -44.634, -135.225, 30.635, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, 59.194, -47.445, -126.406, -151.493, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, 65.956, -48.778, -132.689, -152.282, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, 66.766, -57.091, -177.358, 52.565, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, 66.766, -57.091, -177.358, 52.565, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, 33.321, -58.514, -165.952, 53.655, 5645589},
		{"lok", "enraged_miner_caveLokGasMine", 300, -69.422, -70.848, -155.418, 159.519, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -69.422, -70.848, -155.418, 159.519, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -72.433, -70.793, -158.185, 129.674, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -96.078, -72.557, -179.691, -160.720, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -96.046, -72.184, -181.227, 31.924, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -117.555, -69.356, -202.048, 179.741, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -119.480, -70.936, -150.410, 10.552, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -100.439, -68.888, -136.494, -174.779, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -86.787, -70.089, -128.551, 92.799, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -82.325, -70.248, -123.029, 18.989, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -98.656, -69.509, -93.907, 130.484, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -88.224, -69.996, -94.537, 172.321, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -93.012, -69.932, -97.412, 174.324, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -37.721, -70.466, -108.828, 32.875, 5645593},
		{"lok", "enraged_miner_caveLokGasMine", 300, -53.120, -69.780, -82.962, -158.142, 5645593},
		{"lok", "enraged_miner_caveLokGasMine", 300, -14.029, -69.002, -95.024, -138.990, 5645593},
		{"lok", "enraged_miner_caveLokGasMine", 300, -14.029, -69.002, -95.024, -138.990, 5645593},
		{"lok", "enraged_miner_caveLokGasMine", 300, -18.481, -68.940, -104.938, 77.284, 5645593},
		{"lok", "enraged_miner_caveLokGasMine", 300, -82.418, -98.689, -159.249, -114.547, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -95.825, -101.664, -143.011, 20.014, 5645592},
		{"lok", "enraged_miner_caveLokGasMine", 300, -98.966, -102.213, -126.900, 81.411, 5645595},
		{"lok", "enraged_miner_caveLokGasMine", 300, -80.433, -100.628, -110.631, -105.435, 5645595},
		{"lok", "enraged_miner_caveLokGasMine", 300, -84.829, -99.720, -91.312, -116.243, 5645595},
		{"lok", "enraged_miner_caveLokGasMine", 300, -91.212, -99.732, -90.069, 62.591, 5645595},
	}
}

registerScreenPlay("LokGasMineScreenPlay", true)

function LokGasMineScreenPlay:start()
	if (isZoneEnabled("lok")) then
		self:spawnScreenPMobiles()
	end
end
