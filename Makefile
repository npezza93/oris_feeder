PORT := $(shell arduino-cli board list | grep -i "usb" | awk '{print $$1}')
FQBN := arduino:mbed_giga:giga

compile:
	arduino-cli compile --fqbn "arduino:mbed_giga:giga" ./

upload:
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) ./

install:
	@echo "Installing libraries..."
	@while IFS= read -r lib || [ -n "$$lib" ]; do \
		if [ -n "$$lib" ]; then \
			echo "Installing $$lib..."; \
			arduino-cli lib install "$$lib"; \
		fi \
	done < libraries.txt
