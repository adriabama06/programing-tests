package es.lobby.menus;

import es.lobby.Main;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.inventory.InventoryClickEvent;

public class serversClickListener implements Listener {
    private Main plugin;

    public serversClickListener(Main plugin) {
        this.plugin = plugin;

        plugin.getServer().getPluginManager().registerEvents(this, plugin);
    }

    @EventHandler
    public static void onClick(InventoryClickEvent event) {
        String title = event.getInventory().getTitle();
        if(title.equals(servers.inv_name)) {
            event.setCancelled(true); // Don't take the item
            if(event.getCurrentItem() == null || event.getCurrentItem().getItemMeta() == null) {
                return;
            }
            servers.clicked((Player) event.getWhoClicked(), event.getSlot(), event.getCurrentItem(), event.getInventory(), event);
        }
    }
}
