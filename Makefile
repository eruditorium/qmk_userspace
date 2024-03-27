SHELL := bash
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c
.DELETE_ON_ERROR:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

DOCKER_VERSION:=1.0.1
# Run with "make V=1" to see the actual compile commands
ifdef V
Q=
else
Q=@
MAKEFLAGS += --no-print-directory
endif

docker:
	$(Q)docker build -t qmk-action:$(DOCKER_VERSION) .


build:
	$(Q)docker run \
	-v .:/github/workspace \
	-w /github/workspace \
	docker.io/library/qmk-action:$(DOCKER_VERSION) keyboards/idobao/id75/keymaps/justgook idobao/id75/v1 justgook

.PHONY: build docker
