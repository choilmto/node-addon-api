"use strict";
const assert = require("assert");
const buildType = process.config.target_defaults.default_configuration;

test(require(`./build/${buildType}/binding.node`));
test(require(`./build/${buildType}/binding_noexcept.node`));

function test(binding) {
  assert.strictEqual(binding.env.HasSetImmediate(), true);
  assert.strictEqual(binding.env.HasRequire(), false);
}
